#include"list_child.h"

using namespace std;
void createList_child(List_child &L)
{
    first(L) = NULL;
}

address_child allocate_child(infotype_child X)
{
    address_child P;
    P = new elmlist_child;
    info(P) = X.ID;
    info(P) = X.Nomor;
    info(P) = X.Tanggal;
    next(P) = NULL;
    return P;
}

void deallocate_child(address_child &P)
{
    delete P;
}

void insertFirst_child(List_child &L, infotype_child X)
{
    address_child P;
    P = allocate(X);
    if (first(L) = NULL){
        last(L) = dP;
    }else{
        next(P) = first(L);
    }
    first(L)=P ;
}

void insertAfter_child(address_child &Prec, infotype_child X)
{
    address_child P;
    P = allocate(X);
    if (next(Prec) != NULL){
        next(P) = next(Prec);
    }
    next(Prec) = P;
}

void insertLast_child(List_child &L, infotype_child X)
{
    address_child Prec;
    Prec = first(L);
    if (first(L) = NULL){
        insertFirst(L, X);
    }else{
        while (next(Prec) != null){
           Prec = next(Prec)
        }
        next(Prec) = NULL;
        insertAfter(Prec, X);
    }
}

void deleteFirst_child(List_child &L, address_child &P)
{
   P = first(L);
   first(L) = next(first(L));
   next(P) = NULL;_
}

void deleteLast_child(List_child &L, address_child &P)
{
    address_child Prec;
    Prec = first(L);
    if (next(Prec) = NULL){
        insertFirst(L, P);
    }else{
        while (next(next(Prec)) != NULL){
            Prec = next(Prec);
        }
        next(next(Prec) = NULL;
        deleteAfter(Prec, P);
}

void deleteAfter_child(List_child &L, address_child &P)
{
    address_child Prec;

    if (next(P) != NULL){
       P = next(Prec);
       next(Prec) = next(P);
       next(P)=NULL;
}


void printInfo_child(List_child L) {
    address_child P = first(L);
    int i = 1;
    while (P != NULL) {
        cout << i <<"x"
        P = P -> next;
        i++;
    }
    cout << endl;
}

address_child findElm_child(List_child &L, string X){
    address_child P = first(L);
    while (P != NULL && P -> info.nomor != X) {
        P = next(P);
    }
    return P;
}
