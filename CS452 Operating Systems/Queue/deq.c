#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deq.h"
#include "error.h"

/*
/   ht = head tail
/   ends are its neighbors
/   Rep =  reprentatyion of queue
/
/   @author Andrew Gerber and Buff
/   Note: Left in old code for refrence of work in progress and personal checkmarks
/
*/

// indices and size of array of node pointers
typedef enum
{
  Head,
  Tail,
  Ends
} End;

typedef struct Node
{
  struct Node *np[Ends]; // next/prev neighbors
  Data data;
} * Node;

typedef struct
{
  Node ht[Ends]; // head/tail nodes
  int len;
} * Rep;

static Rep rep(Deq q)
{
  if (!q)
    ERROR("zero pointer");
  return (Rep)q;
}

static void put(Rep r, End e, Data d)
{


  Node newPutNode = (Node)malloc(sizeof(*newPutNode)); //Create new node to put into Rep
  newPutNode->data = d;                                //set data of newnode as args d
  newPutNode->np[Head] = 0;                            //set head to 0 or it would error that valgrind suppresses
  newPutNode->np[Tail] = 0;                            //set tail to 0 or it would error that valgrind suppresses

  if ((r->len == 0))
  { //if no nodes set both as tail and head
    r->ht[Head] = newPutNode;
    r->ht[Tail] = newPutNode;
  }
  //check if e is head or tail
  else if (e == Head)
  { //e is head(left node)

    r->ht[Head]->np[Head] = newPutNode; //set left/head pointer of old head to new node
    newPutNode->np[Tail] = r->ht[Head]; //set new nodes tail pointer to old heads
    r->ht[Head] = newPutNode;           // set new node as r's head
  }

  else if (e == Tail)   //tail is right node
  {

    r->ht[Tail]->np[Tail] = newPutNode; //set left/head pointer of old head to new node
    newPutNode->np[Head] = r->ht[Tail]; //set new nodes tail pointer to old heads
    r->ht[Tail] = newPutNode;           // set new node as r's head
  }

  r->len++;     //reduce length
}

/*
/ check for if there is a item at index i and then return it
/ count from the head ad go up from 0 till you get to i
*/
static Data ith(Rep r, End e, int i)
{
  if (i >= r->len || i < 0)
  {
    //@TODO     CHANGE FOR OTHER ASSINGMENT
    //ERROR("index out of bounds");
    WARN("index out of bounds");      //decided to warn not error so that my testing can work. Can swap for later assignments
    //exit;
    return 0;   //return 0 on error
  }

  Node tmpNode = r->ht[e];    //set up new node as either head or tail node
  End dir = Ends;             //declare a variable dir;
  if (e == Head)
  {
    dir = Tail;       //set dir to the opposite of e
  }
  else if (e == Tail)
  {
    dir = Head;       //set dir to the opposite of e
  }
  else
  { 
    ERROR("e is not head/tail");
    return 0;     //return 0(error) if e is passed in as end
  }

  for (int j = 0; j < i; j++)      //for loop to set tmpnode to node at index i
  {
    tmpNode = tmpNode->np[dir];
  }

  return tmpNode->data;     //return said node at index 1
}



static Data get(Rep r, End e)   //returns the removed node from head or tail of rep
{

  if (r->len == 0)        //THROW WARNING OF NO DATA ERROR IF THERE IS NOTHING IN REP, BASED ON LEN
  {
    //ERROR("Length is 0 - Error no data");
    WARN("Length is 0 - Error no data");
    //exit;
    return 0;
  }

  Data tmp = 0;     //set return tmp data to 0;
  Node delNode;     //create node to set as removed node
  if (r->len == 1)      //if check to see if there is only one node
  {

    delNode = r->ht[Head];    //if there is 1 node set all jazz to that node
    r->ht[Head] = 0;
    r->ht[Tail] = 0;
    //free(delNode);
  }

  else if (e == Head)       //return and delete head node
  { 

    delNode = r->ht[e];
    tmp = r->ht[Head]->data;             //set return data
    r->ht[Head]->np[Tail]->np[Head] = 0; //Set heads right node head pointer to 0
    r->ht[Head] = r->ht[Head]->np[Tail]; //set second node as new head/first
    //free(delNode);
    if (r->len == 2)    
    {
      r->ht[Head] = r->ht[Tail];
    }
  }
  else if (e == Tail)     //return and delete tail node
  { 
    delNode = r->ht[e];
    tmp = r->ht[Tail]->data;
    r->ht[Tail]->np[Head]->np[Tail] = 0; //Set tails left node tail pointer to 0
    r->ht[Tail] = r->ht[Tail]->np[Head]; //set Tails left node as new tail
    //free(delNode);
    if (r->len == 2)      //after removing a node if there is only one more node in list set it pointing to itsself
    {
      r->ht[Tail] = r->ht[Head];
    }
  }
  else
  { 
    ERROR("e is not head/tail");
    return 0;     //return 0(error) if e is passed in as end
  }
  // free(tmpNode);    //delete old head
  r->len--; //reduce length of list
  free(delNode);      //free/delete the node
  return tmp;       //return its data
}

/*
/   loop through doubl linked list and check for d then remove and return
/   d from q
*/
static Data rem(Rep r, End e, Data d)
{

  if (r->len <= 0)    
  {
    //ERROR("Length is 0 - Error no data");
    WARN("Length is 0 - Error no data");
    return 0;
  }
  Data tmp = 0;   //set return tmp value
  End dir;      //set direction
  if (e == Head)
  {
    dir = Tail; //set dir to the opposite of e
  }
  else if (e == Tail)
  {
    dir = Head;   //set dir to the opposite of e
  }
  else
  {
    ERROR("e is not head/tail");
    return 0;     //return 0(error) if e is passed in as end
  }

  Node checkNode = r->ht[e]; //set starting node as head or tail node
  if (r->len == 1)    //if there is only one node
  {
    if (r->ht[Head]->data == d)   //if check to see if only node is correct node
    {
      Node delNode = r->ht[Head];   //set delnode to only node in list
      r->ht[Head] = 0;        //set data to nothing
      r->ht[Tail] = 0;
      free(delNode);    //delete the node
      r->len--;
    }
  }
  else    //if there is more than one node
  {
    for (int i = 0; i < r->len; i++)      //for loop to find data
    {
      if (checkNode->data == d)   //if data = d
      {
        
        tmp = checkNode->data;      // set data to tmp
        if (checkNode->np[Head] != 0)     //if head is not empty
        {
          checkNode->np[Head]->np[Tail] = checkNode->np[Tail]; //set left node
        }
        if (checkNode->np[Tail] != 0)   //if tail is not empty
        {
          checkNode->np[Tail]->np[Head] = checkNode->np[Head];    //set right node
        }
        if (r->len == 2)    //if length is only 2 after
        {
          r->ht[dir] = r->ht[!dir];
        }
        free(checkNode);
        r->len--; //reduce length (OFO)
        return tmp;
      }
      checkNode = checkNode->np[dir];
    }
  }

  //printf("No entity with Data d found");
  return 0;
}

extern Deq deq_new()
{
  Rep r = (Rep)malloc(sizeof(*r));
  if (!r)
    ERROR("malloc() failed");
  r->ht[Head] = 0;
  r->ht[Tail] = 0;
  r->len = 0;
  return r;
}

extern int deq_len(Deq q) { return rep(q)->len; }

//put data on front or left*
extern void deq_head_put(Deq q, Data d) { put(rep(q), Head, d); }
extern Data deq_head_get(Deq q) { return get(rep(q), Head); }
extern Data deq_head_ith(Deq q, int i) { return ith(rep(q), Head, i); }
extern Data deq_head_rem(Deq q, Data d) { return rem(rep(q), Head, d); }

extern void deq_tail_put(Deq q, Data d) { put(rep(q), Tail, d); }
extern Data deq_tail_get(Deq q) { return get(rep(q), Tail); }
extern Data deq_tail_ith(Deq q, int i) { return ith(rep(q), Tail, i); }
extern Data deq_tail_rem(Deq q, Data d) { return rem(rep(q), Tail, d); }

extern void deq_map(Deq q, DeqMapF f)
{
  for (Node n = rep(q)->ht[Head]; n; n = n->np[Tail])
    f(n->data);
}

extern void deq_del(Deq q, DeqMapF f)
{
  if (f)
    deq_map(q, f);
  Node curr = rep(q)->ht[Head];
  while (curr)
  {
    Node next = curr->np[Tail];
    free(curr);
    curr = next;
  }
  free(q);
}

extern Str deq_str(Deq q, DeqStrF f)
{
  char *s = strdup("");
  for (Node n = rep(q)->ht[Head]; n; n = n->np[Tail])
  {
    char *d = f ? f(n->data) : n->data;
    char *t;
    asprintf(&t, "%s%s%s", s, (*s ? " " : ""), d);
    free(s);
    s = t;
    if (f)
      free(d);
  }
  return s;
}
