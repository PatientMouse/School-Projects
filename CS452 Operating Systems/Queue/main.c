#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

int main()
{
  Deq q = deq_new();

  /***********************************************
  /           TEST SUITE
  ************************************************/

  // printf("*************** EMPTY LIST TESTS***************\n");
  // printf("\nTry and remove head on empty list(Should error): \n");
  // printf(deq_head_get(q));
  // printf("\nTry and remove head on empty list(Should error): \n");
  // printf(deq_tail_get(q));
  // printf("\nTry and remove index 0 from head on empty list(Should error): \n");
  // printf(deq_head_ith(q, 0));
  // printf("\nTry and remove index 0 from tail on empty list(Should error): \n");
  // printf(deq_tail_ith(q, 0));
  // printf("\nTry and remove from head on empty list(Should not error): \n");
  // printf(deq_head_rem(q, "Yoink"));
  // printf("\nTry and remove from tail on empty list(Should not error): \n");
  // printf(deq_tail_rem(q, "Yoink"));

  /*                    Put Tests/Fill Que           */
  printf("\n*********************FILLING WITH 10 ENTITYS(STRING)**************\n");
  //Fill deq with 3 Strings from head
  deq_head_put(q, "Head1");
  deq_head_put(q, "Head2");
  deq_head_put(q, "Head3");

  //Fill deq with 3 Strings from tail
  deq_tail_put(q, "Tail1");
  deq_tail_put(q, "Tail2");
  deq_tail_put(q, "Tail3");

  //alternate adding from head to tail
  deq_head_put(q, "Head4");
  deq_tail_put(q, "Tail4");
  deq_head_put(q, "Head5");
  deq_tail_put(q, "Tail5");

  printf("\nList after 10 put's is as follows: ");
  char *s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  /*                    Get Tests           */
  printf("\n *********************** GET TESTS *****************************\n");

  printf("\nAttempt to remove Entity on head and tail: \n\n");
  printf("Removed: ");
  printf(deq_head_get(q)); //test remove head twice  (1/2)
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Removed: ");
  printf(deq_head_get(q)); //test remove head twice    (2/2)
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Removed: ");
  printf(deq_tail_get(q)); //test remove tail twice  (1/2)
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Removed: ");
  printf(deq_tail_get(q)); //test remove tail twice    (2/2)
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  printf("\nempty list with head get..\n");
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);

  //test single delete
  printf("\nadd one to list..\n");
  deq_head_put(q, "Head1");
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("\nRemove solo node with head..\n");
  printf(deq_head_get(q));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  //test single dlete
  printf("\nadd one to list..\n");
  deq_tail_put(q, "Tail1");
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("\nRemove solo node with tail..\n");
  printf(deq_tail_get(q));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  //refill list
  deq_head_put(q, "Head1");
  deq_head_put(q, "Head2");
  deq_head_put(q, "Head3");
  deq_tail_put(q, "Tail1");
  deq_tail_put(q, "Tail2");
  deq_tail_put(q, "Tail3");
  deq_head_put(q, "Head4");
  deq_tail_put(q, "Tail4");
  deq_head_put(q, "Head5");
  deq_tail_put(q, "Tail5");

  printf("Passes get tests.(Cannot test for out of bounds test as no index given");

  printf("\n *********************** ith TESTS *****************************\n");
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("get data of index 0 from head\n");
  printf(deq_head_ith(q, 0));
  printf("\nget data of index 0 from tail\n");
  printf(deq_tail_ith(q, 0));
  printf("\nget data of index 3 from head\n");
  printf(deq_head_ith(q, 3));
  printf("\nget data of index 3 from tail\n");
  printf(deq_tail_ith(q, 3));

  //out of bounds tests
  printf("\nget data of index 10 from Head(OB)\n");
  printf(deq_head_ith(q, 10));
  printf("\nget data of index 10 from tail(OB)\n");
  printf(deq_tail_ith(q, 10));
  printf("\nget data of index 10 from Head(OB)\n");
  printf(deq_head_ith(q, 10));
  printf("\nget data of index 10 from tail(OB)\n");
  printf(deq_tail_ith(q, 10));

  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  printf("\n *********************** rem TESTS*****************************\n");
  printf("\nList: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Remove known value from Head 'Head1':\n");
  printf(deq_head_rem(q, "Head1"));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Remove known value from Head 'Head4':\n");
  printf(deq_head_rem(q, "Head4"));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Remove known value from Tail 'Tail1':\n");
  printf(deq_tail_rem(q, "Tail1"));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);
  printf("Remove known value from 'Tail4':\n");
  printf(deq_tail_rem(q, "Tail4"));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  printf("\nDelete all but two nodes");

  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  deq_head_get(q);
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  printf("Remove one of them wih rem");
  deq_head_rem(q, "Tail5");

  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  //remove single node
  printf("\nRemove solo node with tail..\n");
  printf(deq_tail_rem(q, "Tail3"));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  printf("\nAdd one node\n");
  deq_head_put(q, "Head1");
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);
  free(s);

  printf("\nRemove solo node with head..\n");
  printf(deq_head_rem(q, "Head1"));
  printf("\nList is now: ");
  s = deq_str(q, 0);
  printf("%s\n", s);

  // s=deq_str(q,0);
  // printf("%s\n",s);
  free(s);

  printf("\n\n*****Done*****\n\n");

  deq_del(q, 0);
  return 0;
}



