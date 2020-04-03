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
typedef string infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent
{
    infotype_parent info;
    address_parent next;
    address_parent prev;
    List_child child;
};
struct List_parent
{
    address_parent first;
};

void createList(List_parent &L);
address_parent allocate(infotype_parent X);
void deallocate(address_parent &P);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
address_parent findElm( List_parent, infotype_parent X);
void printInfo(List_parent L);

#endif // LIST_PARENT_H_INCLUDED
