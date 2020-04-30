#include "list_parent.h"
#include "list_child.h"
using namespace std;

void createList(List_parent &L)
{
    first(L) = NULL;
}///igga Febrian Virgiani (1301194283)

address_parent allocate(infotype_parent X)
{
    address_parent P;
    P = new elm_parent;
    info(P).id = X.id;
    info(P).nama= X.nama;
    info(P).kontak = X.kontak;
    next(P) = NULL;
    prev(P) = NULL;
    createList(child(P));
    return P;
}///igga Febrian Virgiani (1301194283)

void deallocate(address_parent &P)
{
    delete P;
}///igga Febrian Virgiani (1301194283)

void insertFirst(List_parent &L, address_parent P)
{
    address_parent Q;
    if (first(L) == NULL ){
       first(L) = P;
       next(P) = P;
       prev(P) = P;
    } else {
        Q = first(L);
        while ( next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        prev(P) = Q;
        next(Q) = P;
        first(L) = P;
    }
}///igga Febrian Virgiani (1301194283)

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}///igga Febrian Virgiani (1301194283)

void insertLast(List_parent &L, address_parent P)
{
    address_parent Q;
    Q = first(L);
    if (first(L) == NULL) {
       first(L) = P;
       next(P) = P;
       prev(P) = P;
    } else {
        while ( next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        prev(P) = Q;
        next(Q) = P;
    }
}///igga Febrian Virgiani (1301194283)

void deleteFirst(List_parent &L, address_parent &P)
{
    address_parent Q;
    if (next(P) == first(L)){
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    } else {
        Q = first(L);
        while (next(next(Q)) != first(L))
        {
            Q = next(Q);
        }
        Q = next(Q);
        first(L) = next(first(L));
        P = next(Q);
        next(Q) = next(P);
        next(P) = NULL;
    }
}///igga Febrian Virgiani (1301194283)

void deleteLast(List_parent &L, address_parent &P)
{
    address_parent Q;
    P = first(L);
    if (next(P) == first(L)){
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    } else {
        Q = first(L);
        while (next(next(Q)) != first(L))
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = next(P);
        next(P) = NULL;
    }
}///igga Febrian Virgiani (1301194283)

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{
    P = next(Prec);
    if (next(next(Prec))== Prec)
    {
        next(P) = NULL;
        prev(P) = NULL;
        next(Prec) = Prec;
        prev(Prec) = Prec;
    }
    else
    {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }

}///igga Febrian Virgiani (1301194283)

address_parent findElm( List_parent L, string X){
    address_parent P;
    if (first(L) != NULL){
        P = first(L);
        do {
            if (info(P).id == X){
                return P;
            }
            P = next(P);
        } while(P != first(L) && info(P).id != X);
    }
}///igga Febrian Virgiani (1301194283)

void printInfo(List_parent L){
address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"Nama :"<<info(P).nama<<endl;
            cout<<"Kontak : "<<info(P).kontak<<endl;
            cout<<"ID : "<< info(P).id<<endl;
            printInfo_Child(child(P));
            P = next(P);
        } while((P)!=first(L));
    }
}///igga Febrian Virgiani (1301194283)

address_parent searchByID_p(List_parent L, string x ){
    address_parent P;
    P = first(L);
    do {
        if (info(P).id == x ){
            return P;
        }
        P = next(P);
    }while (P != NULL && info(P).id == x);
}///igga Febrian Virgiani (1301194283)
