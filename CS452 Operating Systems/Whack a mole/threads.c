#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "deq.h"
#include "threads.h"
#include "error.h"
//@author andrew gerber
//purpose multi thread multi call function
extern void multiCall(int n, void *args ){
  void **a = args;

  //pthread_mutex_lock(&lock);
  
  pthread_t threadIDPro[n];
  pthread_t threadIDCon[n];
  
  for (int i=0; i<n; i++){
    pthread_create(&threadIDPro[i],NULL,a[2],a);
    pthread_create(&threadIDCon[i],NULL,a[3],a);
  }
  //sleep(10);
  for (int i=0; i<n; i++){
    //pthread_create(&threadIDPro[i],NULL,a[2],a);
    //pthread_create(&threadIDCon[i],NULL,a[3],a);
  }
  for (int i=0; i<n; i++){
    pthread_join(threadIDPro[i],0);
    pthread_join(threadIDCon[i],0);
  }
}