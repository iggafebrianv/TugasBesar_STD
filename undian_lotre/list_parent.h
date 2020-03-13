#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#include "list_child.h"
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child



#endif // LIST_PARENT_H_INCLUDED
