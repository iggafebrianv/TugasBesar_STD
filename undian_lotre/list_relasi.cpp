#include "list_relasi.h"

/** Nama : Igga Febrian Virgiani
    NIM  : 1301194283
**/
void deleteFirstParent(List_parent &L, address_parent &P){
    address_child C;
    P = first(L);
    do{
        deleteFirst(child(P),C);
        delete C;
    }while(first(child(P)) != first(L));
    deleteFirst(L,P);
}
void printRelasi(address_parent P, address_child C){
    P = first(L);

    do {
        cout<< "Info Pemain : " << info(P)<<endl;
        cout << "no lotre yang dimiliki pemain : ";
        C = first(P);
        while (C != NULL){
            if (child(P) == C){
                cout<<info(ch)<<", ";
            }
            C = next(C);
        }
        cout<<endl;
        P = next(P);
    }while ( P != first(L));
}
