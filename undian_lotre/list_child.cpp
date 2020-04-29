#include "list_child.h"
#include "stdlib.h"
#include <iostream>

/** Nama : Igga Febrian Virgiani
    NIM  : 1301194283
**/

void createList(List_child &L){
    first(L) = NULL;
}///igga Febrian Virgiani (1301194283)
address_child allocate_c(infotype_child x){
    address_child P;
    P = new elmlist_child;
    info(P).lotre = x.lotre;
    info(P).tanggal = x.tanggal;
    info(P).ID = x.ID;

    return P;
}///igga Febrian Virgiani (1301194283)
void insertFirst(List_child &L, address_child P){
    if (first(L) == NULL){
        first(L) = P;
    }else {
        next(P) = first(L);
        first(L) = P;
    }
}///igga Febrian Virgiani (1301194283)
void insertAfter(List_child &L, address_child P, address_child Prec){
    if (first(L) != NULL && Prec != NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    } else {
        insertLast(L,P);
    }
}///igga Febrian Virgiani (1301194283)
void insertLast(List_child &L, address_child P){
    if(first(L) == NULL){
        insertFirst(L,P);
    } else {
        address_child Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}///igga Febrian Virgiani (1301194283)
void deleteFirst(List_child &L,address_child P){
   if (first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
   }
}///igga Febrian Virgiani (1301194283)
void deleteAfter(List_child &L,address_child P, address_child Prec)
{
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}///igga Febrian Virgiani (1301194283)
void deleteLast(List_child &L,address_child P){
    if (first(L) != NULL){
        address_child Q = first(L);
        if (next(Q) = NULL){
            deleteFirst(L,P);
        } else {
            while (next(next(Q)) != NULL){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
            next(P) = NULL;
        }
    }
}///igga Febrian Virgiani (1301194283)
void deallocate_c(address_child &P){
    delete P;
}///igga Febrian Virgiani (1301194283)
address_child findElm_C(List_child &L,int X){
    address_child P = first(L);
    while (P != NULL){
        if (info(P).ID == X){
            return P;
        }
        P = next(P);
    }
    return NULL;
}///igga Febrian Virgiani (1301194283)
void printInfo_Child(List_child L){
    address_child P = first(L);
    while (P != NULL){
        cout<<"----------------------------------------"<<endl;
        cout<< "No Undian Lotre : " << info(P).lotre << endl;
        cout<< "Tanggal Pembelian Lotre : " << info(P).tanggal<<endl;
        cout<< "ID Lotre : " << info(P).ID<< endl;
        cout<<"----------------------------------------"<<endl;
        P = next(P);
    }
    cout<<endl;
}///igga Febrian Virgiani (1301194283)

int randomPemenang(){
    int rndm = 100000 + rand() % 999999;
    return rndm;
}///igga Febrian Virgiani (1301194283)
