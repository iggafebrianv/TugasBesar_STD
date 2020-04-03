#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct elmlist_child*address_child;
typedef int infotype_child;

struct elmlist_child{
	infotype_child info;
	address_child next;
};

struct List_child{
	address_child first;
	address_child last;
};

void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertAfter(List_child &L, address_child P, address_child Prec);
void insertLast(List_child &L, address_child P);

void deleteFirst(List_child &L,address_child P);
void deleteAfter(List_child &L,address_child P, address_child Prec);
void deleteLast(List_child &L,address_child P);

void dealokasi(address_child &P);
address_child alokasi(infotype_child x);
address_child searchNumber(List_child &L,infotype_child X);
void printInfo(List_child L);//



#endif // LIST_CHILD_H_INCLUDED
