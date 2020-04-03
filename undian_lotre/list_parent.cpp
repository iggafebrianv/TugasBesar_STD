#include "list_parent.h"
#include "list_child.h"
using namespace std;

void createList(List_parent &L)
{
    first(L) = NULL;
}

address_parent allocate(infotype_parent X)
{
    address_parent P;
    P = new elmlist_parent;
    info(P) = X;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void deallocate(address_parent &P)
{
    delete P;
}

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

}

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    next(Prec) = P;
    prev(P) = Prec;
}

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
}

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
}

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
}

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

}

address_parent findElm( List_parent L, infotype_parent X){
    address_parent P;
    P = first(L);
    do {
        if(info(P) == X) {
            return P;
        }
        P = next(P);
    } while(P != first(L) || info(P) != X);
    return NULL;
}

void printInfo(List_parent L){
address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            printInfo(child(P));
            P = next(P);
        } while((P)!=first(L));
    }
}
