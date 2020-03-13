#include "list_parent.h"


void createList(List_parent &L)
{
    first(L) = NULL;
}

void insertFirst(List_parent &L, address_parent P)
{
    if (first(L) == NULL )
    {
       first(L) = P;
       next(P) = P;
       prev(P) = P;
    }
    else
    {
         next(P) = first(L);
         prev(P) = prev(first(L));
         next(prev(first(L))) = P;
         prev(first(L)) = P;
         first(L) = P;
    }

}
void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{

}
void insertLast(List_parent &L, address_parent P)
{

}
void deleteFirst(List_parent &L, address_parent &P)
{

}
void deleteLast(List_parent &L, address_parent &P)
{

}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{

}
