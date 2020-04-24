#include "list_child.h"
#include"list_child.h"

using namespace std;
void createList(List_child &L)
{
    first(L) = NULL;
}

address_child allocate(infotype_child X)
{
    address_child P;
    P = new elmlist_child;
    info(P) = X;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void deallocate(address_child &P)
{
    delete P;
}

void insertFirst(List_child &L, address_child P)
{
    address_child Q;
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

}

void insertAfter(List_child &L, address_child Prec, address_child P)
{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    next(Prec) = P;
    prev(P) = Prec;
}

void insertLast(List_child &L, address_child P)
{
    address_child Q;
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
}

void deleteFirst(List_child &L, address_child &P)
{
    address_child Q;
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
}

void deleteLast(List_child &L, address_child &P)
{
    address_child Q;
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
}

void deleteAfter(List_child &L, address_child Prec, address_child &P)
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

}

address_child searchNumber( List_child L, infotype_child X){
    address_child P;
    P = first(L);
    do {
        if(info(P) == X) {
            return P;
        }
        P = next(P);
    } while(P != first(L) || info(P) != X);
    return NULL;
}

void printInfo(List_child L){
address_child P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            printInfo(child(P));
            P = next(P);
        } while((P)!=first(L));
    }
}
