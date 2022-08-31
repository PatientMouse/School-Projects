#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//@author andrew Gerber
#include "mtq.h"
#include "error.h"
#include "deq.h"
#include "threads.h"
#include "mole.h"

typedef struct{
  pthread_mutex_t lock;
  pthread_cond_t sig;
  Deq que;
  int size; //length of mtq
  int maxSize;
} * Rep;

static Rep mtqRep(Mtq q){
  if (!q)
    ERROR("zero pointer");
  return (Rep)q;
}
/*
*     mtq new
*     @Param int of max size of queue (not implimented)
*     Purpose: make a new mtq
*/
extern Mtq mtq_new(int max)
{
  if(!max){
    ERROR("Invalid input");}
  //pthread_mutex_lock(&q->lock);
  //Mtq newQueue = (Mtq)malloc(sizeof(*newQueue));
  Rep returnQ = (Rep)malloc(sizeof(*returnQ));
                 returnQ->que = deq_new();
                 returnQ->maxSize = max;
                 returnQ->size = 0; //length of mtq
  pthread_mutex_init(&returnQ->lock,0);
  pthread_cond_init(&returnQ->sig,0);   //addable needs to be 1, this is retrivable cond
  // returnQ->que = deq_new();
  // returnQ->size = max;
  // pthread_mutex_init(&returnQ->lock,0);
  //pthread_cond_signal(&q->sig);
  //pthread_mutex_unlock(&q->lock);
  return returnQ;
}
//returns a int of length of the mtq, takes a q
extern int mtq_len(Mtq q) { 
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);

  int tmp = deq_len(r);
    
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  return tmp;
}
//thread safe wrapper for head put
 extern void mtq_head_put(Mtq q, Data d) { 
   if(!q){
    ERROR("Invalid input");}
    Rep r = mtqRep(q);
    pthread_mutex_lock(&r->lock);

    deq_head_put(r->que,d);
    r->size++;
    
    pthread_cond_signal(&r->sig);
    pthread_mutex_unlock(&r->lock);
}
//thread safe wrapper for tail put
 extern void mtq_tail_put(Mtq q, Data d) { 
   if(!q){
    ERROR("Invalid input");}
    Rep r = mtqRep(q);
    pthread_mutex_lock(&r->lock);

    deq_tail_put(r->que,d);
    r->size++;
    
    pthread_cond_signal(&r->sig);
    pthread_mutex_unlock(&r->lock);
    
}
//thread safe wrapper for head get
 extern Data mtq_head_get(Mtq q){
   if(!q){
    ERROR("Invalid input");}
  //  if (&q->size < 0 || &q->size > &q->maxSize)   {
  //    ERROR("OB");
  //  }
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);

  while(r->size == 0){
    pthread_cond_wait(&r->sig,&r->lock);
  }
   
  Data tmp = deq_head_get(r->que);//change to mole from Data back to mole
  r->size--;   
  //que length starts at 33
  //

  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  
  return tmp;
}
//thread safe wrapper for tail put
 extern Data mtq_tail_get(Mtq q){
   if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);


  
  //while(r->size == 0){
  while(!(r->size >0)){
    //printf("\nEnter\n");
    pthread_cond_wait(&r->sig,&r->lock);
  }
   //printf("\nExit\n");
  Data tmp = deq_tail_get(r->que);//change to mole from Data back to mole
  r->size--;   
  //que length starts at 33
  //

  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  
  return tmp;
}
//thread safe wrapper for head ith
extern Data mtq_head_ith(Mtq q, int i){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);

  Data tmp = deq_head_ith(r,i);
    
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  return tmp;
}
//thread safe wrapper for tail ith
extern Data mtq_tail_ith(Mtq q, int i){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);

  Data tmp = deq_tail_ith(r,i);
    
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  return tmp;
}
//thread safe wrapper for head rem
extern Data mtq_head_rem(Mtq q, Data d){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);

  Data tmp = deq_head_rem(r,d);
    
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  return tmp;
}
//thread safe wrapper for tail rem
extern Data mtq_tail_rem(Mtq q, Data d){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);

  Data tmp = deq_tail_rem(r,d);
    
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  return tmp;
}
//thread safe wrapper for mtq map
extern void mtq_map(Mtq q, DeqMapF f){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);
  deq_map(r,f);
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
}
//thread safe wrapper for deq del
extern void mtq_del(Mtq q, DeqMapF f){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  
  deq_del(r->que,f);
  //free(r);
  free(q);
}
//thread safe wrapper for mtw str
extern Str mtq_str(Mtq q, DeqStrF f){
  if(!q){
    ERROR("Invalid input");}
  Rep r = mtqRep(q);
  pthread_mutex_lock(&r->lock);
  Data tmp = deq_str(r->que,f);
  pthread_cond_signal(&r->sig);
  pthread_mutex_unlock(&r->lock);
  return tmp;
}