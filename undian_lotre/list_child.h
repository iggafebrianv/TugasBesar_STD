#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct elmlist_child*address_child

struct elmlist_child{
	infotype info;
	address next;
}

struct list_child{
	address_child first;
	address_child last;
}

void createList(List &L);

void insertFirst(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void insertLast(List &L, address P);

void deleteFirst(List &L,address P);
void deleteAfter(List &L,address P, address Prec);
void deleteLast(List &L,address P);

void dealokasi(address_child &P);
address_child alokasi(infotype_child x);
address_child searchNumber(list_child L &L,infotype);
void printInfo(List_child L);
