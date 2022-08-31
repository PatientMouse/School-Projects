#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

#include "lawn.h"
#include "mole.h"
#include "deq.h"
#include "threads.h"
#include "mtq.h"
 //@andrew Gerber
/*
*     Produce functions (head/tail)
*     @Param void pointer to array of args
*     Purpose: These static functions produce and then add a mole to a multi threaded queue onto the head or the tail of the mtq
*/
static void *produceTail(void *a){
  void **arg=a;
  Mtq q = (Mtq)arg[0];
  Lawn l = (Lawn)arg[1];
  mtq_tail_put(q,mole_new(l,0,0));
  return 0;}

static void *produceHead(void *a){ 
  void **arg=a;
  Mtq q = (Mtq)arg[0];
  Lawn l = (Lawn)arg[1];
  mtq_head_put(q,mole_new(l,0,0));
  return 0;}
/*
*     Consume functions (head/tail)
*     @Param void pointer to array of args
*     Purpose: These static functions consumes a mole off the mutli threaded queue
*/
static void *consumeTail(void *a) { 
  void **args =a;
  Mtq q = (Mtq)args[0];
  mole_whack(mtq_tail_get(q)); 
  return 0;}   

static void *consumeHead(void *a) { 
  void **args =a;
  Mtq q = (Mtq)args[0];
  mole_whack(mtq_head_get(q)); 
  return 0;}   


int main() {
  Mtq mq = mtq_new(10);

  srandom(time(0));
  const int times=100;
  Lawn lawn=lawn_new(0,0);


  void *args[6];
  args[0] = mq;
  args[1] = lawn;
  args[2] = produceHead;
  args[3] = consumeHead;
  args[4] = produceTail;
  args[5] = consumeTail;

  multiCall(times,args);

  
  mtq_del(mq,0);
  lawn_free(lawn);
}








//              TEST SUIT FOR ISOLATED MTQ          
// int main(){       //MTQ TESTING MAIN
//   Mtq mq = mtq_new(10);
// printf("\n*********************FILLING WITH 1 ENTITYS(STRING)**************\n");
//   //Fill deq with 3 Strings from head
//   mtq_head_put(mq, strdup("Head1"));
//   mtq_head_put(mq, strdup("Head2"));
//   mtq_head_put(mq, strdup("Head3"));
 
//  //Fill deq with 3 Strings from tail
//   mtq_tail_put(mq, "Tail1");
//   mtq_tail_put(mq, "Tail2");
//   mtq_tail_put(mq, "Tail3");

//   //alternate adding from head to tail
//   mtq_head_put(mq, "Head4");
//   mtq_tail_put(mq, "Tail4");
//   mtq_head_put(mq, "Head5");
//   mtq_tail_put(mq, "Tail5");
//   printf("\nList after 10 put's is as follows: ");
//   char *s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);
//  /*                    Get Tests           */
//   printf("\n *********************** GET TESTS *****************************\n");

//   printf("\nAttempt to remove Entity on head and tail: \n\n");
//   printf("Removed: ");
//   printf(mtq_head_get(mq)); //test remove head twice  (1/2)
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);
//   printf("Removed: ");
//   printf(mtq_head_get(mq)); //test remove head twice    (2/2)
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);
//   printf("Removed: ");
//   printf(mtq_tail_get(mq)); //test remove tail twice  (1/2)
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);
//   printf("Removed: ");
//   printf(mtq_tail_get(mq)); //test remove tail twice    (2/2)
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);

//   printf("\nempty list with head get..\n");
//   mtq_head_get(mq);
//   mtq_head_get(mq);
//   mtq_head_get(mq);
//   mtq_head_get(mq);
//   mtq_head_get(mq);
//   mtq_head_get(mq);

//   //test single delete
//   printf("\nadd one to list..\n");
//   mtq_head_put(mq, "Head1");
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);
//   printf("\nRemove solo node with head..\n");
//   mtq_head_get(mq);
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);

//   //test single dlete
//   printf("\nadd one to list..\n");
//   mtq_tail_put(mq, "Tail1");
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);
//   printf("\nRemove solo node with tail..\n");
//   mtq_tail_get(mq);
//   printf("\nList is now: ");
//   s = mtq_str(mq, 0);
//   printf("%s\n", s);
//   free(s);

// }



