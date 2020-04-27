#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

/** Nama : Igga Febrian Virgiani
    NIM  : 1301194283
**/

typedef struct elmlist_child*address_child;
struct infotype_child{
    int lotre;
    int tanggal;
    int ID;
};
struct elmlist_child{
	infotype_child info;
	address_child next;
};

struct List_child{
	address_child first;
};

void createList(List_child &L);
address_child allocate_c(infotype_child x);
void insertFirst(List_child &L, address_child P);
void insertAfter(List_child &L, address_child P, address_child Prec);
void insertLast(List_child &L, address_child P);
void deleteFirst(List_child &L,address_child P);
void deleteAfter(List_child &L,address_child P, address_child Prec);
void deleteLast(List_child &L,address_child P);
void deallocate_c(address_child &P);
address_child findElm_C(List_child &L,infotype_child X);
void printInfo_Child(List_child L);//



#endif // LIST_CHILD_H_INCLUDED
