#include <iostream>
#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;
/** Nama : Igga Febrian Virgiani
    NIM  : 1301194283
**/
int main()
{
    bool found;
    List_parent LP;
    List_child LC;
    infotype_parent P;
    infotype_child N;
    createList(LP);
    createList(LC);
    string q;
    int menu, s, x, total = 0;
  do{
    system("CLS");
    cout<<"*=====================================================*"<<endl;
    cout<<"*||        SELAMAT DATANG DALAM PERMAINAN LOTRE     ||*"<<endl;
    cout<<"*=====================================================*"<<endl;
    cout<<"* 1. Membuat data Pembeli undian lotre                *"<<endl;
    cout<<"* 2. Menampilkan semua data pembeli                   *"<<endl;
    cout<<"* 3. Membuat data tiket lotre yang terjual            *"<<endl;
    cout<<"* 4. Menampilkan data pembeli beserta lotrenya        *"<<endl;
    cout<<"* 5. Mencari data pembeli berdasarkan ID pembeli      *"<<endl;
    cout<<"* 6. Mencari data tiket lotre berdasarkan ID pembeli  *"<<endl;
    cout<<"* 7. Menghapus data tiket lotre milik pembeli         *"<<endl;
    cout<<"* 8. Menghapus data pembeli                           *"<<endl;
    cout<<"* 9. Menampilkan nomor lotre pemenang                 *"<<endl;
    cout<<"*=====================================================*"<<endl;
    cout<<"* Silahkan Pilih Menu (Angka): ";
    cin>> menu;
    switch(menu){
        case 1:{
            system("CLS");
            cout<<"*=============INPUT DATA PEMBELI=============*"<<endl;
            cout<<"* Nama       : ";
            cin.get();
            getline(cin,P.nama);
            cout<<"* Kontak     : ";
            cin>>P.kontak;
            cout<<"* ID Pembeli : ";
            cin>>P.id;
            if(first(LP) == NULL){
                insertFirst(LP,allocate(P));
            }else {
                address_parent Q = first(LP);
                do{
                   if (info(Q).id == P.id){
                    found = true;
                   }
                   Q = next(Q);
                }while (Q != first(LP) );
                if (!found){
                    insertLast(LP,allocate(P));
                }else {
                    cout << "ID Pembeli telah terdaftar" << endl;
                }
            }
            cout<<"Press Enter to Continue...";
            getch();
                break;
        }
        case 2:{
            system("CLS");
            cout<<"*============DATA PEMBELI==============*"<<endl;
            printInfo(LP);
            cout<<"Press Enter to Continue";
                getch();
        }
            break;





    }


    }while (menu != 0);





    return 0;
}
