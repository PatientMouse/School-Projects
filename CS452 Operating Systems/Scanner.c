#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("BSU CS 452 HW4");
MODULE_AUTHOR("andrew G and buff code");

//write uses getline/getdelim
typedef struct
{
  dev_t devno;
  struct cdev cdev;
  char *s;
  char *sep;
} Device; /* per-init() data */

typedef struct
{
  char *str;
  int writeFlag;
  char *seper;
  size_t strLocation;
  size_t strSize;
} File; /* per-open() data */

typedef struct
{
  File *private_data;
  //others? CHECK
} filepd;

static Device device;

/**
 * @name sepCheck
 * @description checks if the given char is one of the separators
 * @param char check
 * @param char sep 
 * 
 * @returns unsigned int
 */
unsigned int sepCheck(char check, char *sep)
{
  while (*sep != '\0'){ //while not end of string
    if (check == *sep){//if char is a sep
      return 1;
    }
    check++;
  }
  return 0;
}

/**
 * @name tokenizer
 * @description takes in a string and a seperator and returns a tokenized string. NOT USED
 * @param char *sequence 
 * @param char* sep
 * 
 * @returns char *
 */
char *tokenizer(char *sequence, char *sep)
{
  char *token;
  static char *oldSequence;

  if (!sequence)
  { //this check is incase we pass in a null seq to reset the tokenizer
    sequence = oldSequence;
  }
  if (!sep)
  {
    //ERROR("no input 2");
  }
  if (!sequence)
  {
    return NULL;
  }
  while (1)
  { //loop forever and will exit when eof or at sep??
    if (sepCheck(*sequence, sep))
    {
      sequence++;
      continue;
    }
    if (*sequence == '\0')
    {
      return NULL;
    }
    break;
  }
  token = sequence;
  while (1)
  {
    if (*sequence == '\0')
    {
      oldSequence = sequence;
      return token;
    }
    if (sepCheck(*sequence, sep))
    {
      *sequence = '\0';
      oldSequence = sequence + 1;
      return token;
    }
    sequence++;
  }
}

/**
 * @name ioctl
 * @description ioctl function for the device, sets the write flag if called
 * @param struct file filep
 * @param unsigned int cmd 
 * @param unsigned long arg
 * 
 * @returns long
 */
static long ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
  File *file = filp->private_data;
  file->writeFlag = 1;
  return 0;
}

/**
 * @name write
 * @description writes to the device, if the write flag is set, it will write to the string
 * @param struct file filp
 * 
 * @returns sstize_t
 */
static ssize_t write(struct file *filp,
                     const char *line,
                     size_t count,
                     loff_t *f_pos)
{
  File *f = filp->private_data;
  printk(KERN_DEBUG "%s: entering write\n", DEVNAME);
  if (f->writeFlag == 1){//if write flag is set
    kfree(f->seper);
    f->seper = (char *)kmalloc((count + 1), GFP_KERNEL);
    //int seplen = strlen(line);
    //f->seper = line;
    if (copy_from_user(f->seper, line, count))
    {
      printk(KERN_ERR "%s: copy_from_user() failed\n", DEVNAME);
      return 0;
    }
    return count;
  }
  else
  {
    //f->str = line;
    f->str = (char *)kmalloc((count + 1), GFP_KERNEL);
    f->strSize = count;
    f->strLocation = 0;
    if (copy_from_user(f->str, line, count) != 0)
    { //if copy from user fails
      printk(KERN_ERR "%s: copy_from_user() failed\n", DEVNAME);
      return 0;
    }
    //   int n=strlen(line);
    //   n=(n<count ? n : count);
    //   if (copy_from_user(f->str,line,n)) {
    //   printk(KERN_ERR "%s: copy_from_user() failed\n",DEVNAME);
    //   return 0;
    // }
    return count;
  }
}

/**
 * @name tokenizeV2
 * @description takes the string loaction and size and tokenizes the string based on that information
 * @param file F
 * 
 * @returns char *
 */
char *tokenizeV2(File *f)
{
  char *seps = f->seper;
  char *str = f->str;
  //size_t strSize = f->strSize;
  size_t strLocation = f->strLocation;

  char *returnStr = NULL;
  char strChar = str[strLocation];
  int index = 0;
  if (sepCheck(strChar, seps) == 1){ //if the char is a seperator
    return returnStr;
  }
  while (sepCheck(strChar, seps) != 1)
  { //while the char is not a seperator

    returnStr[index] = strChar;
    returnStr[index + 1] = '\0';
    index++;
    strLocation++;
    strChar = str[strLocation];
  }

  strLocation++;
  return returnStr;
}

/**
 * @name read
 * @description reads the next token from ther string
 * @param struct file *filp
 * @param char *buf
 * @param size_t count 
 * @param loff_t *f_pos
 * @returns ssize_t
 */
static ssize_t read(struct file *filp,
                    char *buf,
                    size_t count,
                    loff_t *f_pos)
{

  File *file = filp->private_data;
  //char *delim = file->seper;
  //char *str = file->str;
  size_t location = file->strLocation;
  char *output;
  int n;

  output = tokenizeV2(file);
  if (output == NULL)
  {
    output = tokenizeV2(file);
  }

  if (copy_to_user(buf, output, location))
  { //copy the token to the user
    printk(KERN_ERR "%s: copy_to_user() failed\n", DEVNAME);
    return 0;
  }
  n = strlen(output);

  if (n == 0)
  {
    if (file->strSize == file->strLocation)
    {
      return -1;
    }
  }
  return n;
}

static int release(struct inode *inode, struct file *filp)
{
  File *file = filp->private_data;
  kfree(file->str);
  kfree(file->seper);
  kfree(file->str);
  kfree(file);
  return 0;
}

static int open(struct inode *inode, struct file *filp)
{
  File *file = (File *)kmalloc(sizeof(*file), GFP_KERNEL);
  if (!file)
  {
    printk(KERN_ERR "%s: kmalloc() failed\n", DEVNAME);
    return -ENOMEM;
  }
  file->str = (char *)kmalloc(strlen(device.s) + 1, GFP_KERNEL);
  if (!file->str)
  {
    printk(KERN_ERR "%s: kmalloc() failed\n", DEVNAME);
    return -ENOMEM;
  }
  strcpy(file->str, device.s); //copy string
  filp->private_data = file;
  return 0;
}

static struct file_operations ops = {
    .open = open,
    .release = release,
    .read = read,
    .write = write,
    .unlocked_ioctl = ioctl,
    .owner = THIS_MODULE};

static int __init my_init(void)
{
  const char *s = "Hello world!\n";
  int err;
  const char *sep = ": ";
  device.s = (char *)kmalloc(strlen(s) + 1, GFP_KERNEL);
  if (!device.s)
  {
    printk(KERN_ERR "%s: kmalloc() failed\n", DEVNAME);
    return -ENOMEM;
  }
  strcpy(device.s, s);
  err = alloc_chrdev_region(&device.devno, 0, 1, DEVNAME);
  if (err < 0)
  {
    printk(KERN_ERR "%s: alloc_chrdev_region() failed\n", DEVNAME);
    return err;
  }
  cdev_init(&device.cdev, &ops);
  device.cdev.owner = THIS_MODULE;
  err = cdev_add(&device.cdev, device.devno, 1);
  if (err)
  {
    printk(KERN_ERR "%s: cdev_add() failed\n", DEVNAME);
    return err;
  }
  printk(KERN_INFO "%s: init\n", DEVNAME);

  device.sep = (char *)kmalloc(strlen(s) + 1, GFP_KERNEL);

  strcpy(device.sep, sep); //copy in the defualt seperstors into device
  return 0;
}

static void __exit my_exit(void)
{
  cdev_del(&device.cdev);
  unregister_chrdev_region(device.devno, 1);
  kfree(device.s);
  printk(KERN_INFO "%s: exit\n", DEVNAME);
}

// static int open(struct inode *inode, struct file *filp) {
//   File *file=(File *)kmalloc(sizeof(*file),GFP_KERNEL);
//   if (!file) {
//     printk(KERN_ERR "%s: kmalloc() failed\n",DEVNAME);
//     return -ENOMEM;
//   }
//   file->str=(char *)kmalloc(strlen(device.s)+1,GFP_KERNEL);
//   if (!file->str) {
//     printk(KERN_ERR "%s: kmalloc() failed\n",DEVNAME);
//     return -ENOMEM;
//   }
//   strcpy(file->str,device.s);//copy string CHECK
//   filp->private_data=file;
//   return 0;
// }

module_init(my_init);
module_exit(my_exit);
