#include "list_relasi.h"

/** Nama : Igga Febrian Virgiani
    NIM  : 1301194283
**/
void printRelasi(address_parent pr, address_child ch){
    address_parent P;
    address_child C;

    P = first(pr);

    do {
        cout<< "Info Pemain : " << info(P)<<endl;
        cout << "no lotre yang dimiliki pemain : ";
        C = first(ch);
        while (C != NULL){
            if (child(P) == C){
                cout<<info(ch)<<", ";
            }
            C = next(C);
        }
        cout<<endl;
        P = next(P);
    }while ( P != first(pr));
}
