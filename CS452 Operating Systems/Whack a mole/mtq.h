#ifndef MTQ_H
#define MTQ_H

#include "deq.h"

//wrapper method of deq to call the respective functions while mt safe
//@author andrew G

typedef void *Mtq;
typedef void *Data;


//typedef void *Data;

extern Mtq mtq_new();
extern int mtq_len(Mtq q);

extern void mtq_head_put(Mtq q, Data d);
extern Data mtq_head_get(Mtq q);
extern Data mtq_head_ith(Mtq q, int i);
extern Data mtq_head_rem(Mtq q, Data d);

extern void mtq_tail_put(Mtq q, Data d);
extern Data mtq_tail_get(Mtq q);
extern Data mtq_tail_ith(Mtq q, int i);
extern Data mtq_tail_rem(Mtq q, Data d);

typedef char *Str;
typedef void (*MtqMapF)(Data d);
typedef Str  (*MtqStrF)(Data d);

extern void mtq_map(Mtq q, MtqMapF f); // foreach
extern void mtq_del(Mtq q, MtqMapF f); // free
extern Str  mtq_str(Mtq q, MtqStrF f); // toString

#endif