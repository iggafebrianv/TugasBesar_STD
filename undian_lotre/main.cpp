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
    bool found, terdaftar;
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
    cout<<"* 6. Mencari data tiket lotre berdasarkan ID          *"<<endl;
    cout<<"* 7. Menghapus data tiket lotre milik pembeli         *"<<endl;
    cout<<"* 8. Menghapus data pembeli                           *"<<endl;
    cout<<"* 9. Menampilkan nomor lotre pemenang                 *"<<endl;
    cout<<"*=====================================================*"<<endl;
    cout<<"* Silahkan Pilih Menu (Angka): ";
    cin>> menu;
    switch(menu){
        case 1:{
            system("CLS");
            /// Igga Febrian Virgiani (1301194283)///
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
                terdaftar = true;
            }else {
                address_parent Q = first(LP);
                do{
                   if (info(Q).id == P.id){
                    cout<<"Maaf ID Pembeli telah terdaftar silahkan input kembali "<<endl;
                    found = true;
                    cout<<"* ID Pembeli : ";
                    cin>>P.id;
                   }else if (!found) {
                      insertLast(LP,allocate(P));
                      terdaftar = true;
                   }
                   Q = next(Q);
                }while (Q != first(LP) );
            if (terdaftar){
                cout << "ID Pembeli telah terdaftar" << endl;
            }
                }
             cout<<"Press Enter to Continue...";
            getch();
        }
        break;

        case 2:{
            system("CLS");
            ///Igga Febrian Virgiani (1301194283)///
            cout<<"*============DATA PEMBELI==============*"<<endl;
            printInfo(LP);
            cout<<"Press Enter to Continue";
                getch();
        }
        break;

        case 3:{
        ///Igga Febrian Virgiani (1301194283)///
           system("CLS");
           cout<<"*============INPUT DATA LOTRE=============*"<<endl;
           cout<<"* Silahkan Masukan ID Pembeli :           ";
           string P;
           cin>>P;
           if (findElm(LP,P) != NULL){
                cout<<"ID Pembeli Telah Ditemukan selanjutnya silahkan input data lotre"<<endl;
                cout<<"* Angka Lotre :     ";
                cin>>N.lotre;
                cout<<"* Tanggal Pembelian :      ";
                cin>>N.tanggal;
                cout<<"* ID Lotre :       ";
                cin>>N.ID;
                if (findElm_C(LC,N) != NULL ){
                    cout<<"Maaf ID Lotre telah digunakan, silahkan input kembali: ";
                    cout<<"* ID Lotre :       ";
                    cin>>N.ID;
                }else{
                    insertFirst(LC, allocate_c(N));
                }
           }else {
            cout<<"Maaf ID Pembeli tidak ditemukan, proses input data lotre tidak bisa dilakukan"<<endl;
           }
           cout<<"Please Enter to Continue..."<<endl;
           getch();
        }
        break;


      case 4:{
        system("CLS");
        ///Igga Febrian Virgiani (1301194283)///
            cout<<"*============DATA PEMBELI==============*"<<endl;
            address_parent D;
            address_child E;
            printRelasi(D,E);
            cout<<"Press Enter to Continue";
                getch();
      }
      break;

      case 5:{
          system("CLS");
          ///Igga Febrian Virgiani (1301194283)///
          cout<<"*===========Mencari Pembeli berdasarkan ID===============*"<<endl;
          cout<<"* Masukan ID Parent :                   ";
          cin.get();
          getline(cin,q);
          address_parent P;
          if ( P == NULL){
            cout<<"ID Pembeli"<<q<<"tidak ditemukan"<<endl;
          }else {
            findElm(LP,q);
          }
          cout<<"Press Enter to Continue...";
          getch();
      }
      break;

      case 6:{
          system("CLS");
          ///Igga Febrian Virgiani (1301194283)///
          cout<<"*===========Mencari Lotre berdasarkan ID============*"<<endl;
          cout<<"* Masukan ID Lotre :       ";
          cin>>x;
          address_child P = first(LC);
          if ( P == NULL){
            cout<<"Maaf ID Lotre Tidak Ditemukan"<<endl;
          }else{
              findElm_C(LC,x);
          }
          cout<<"Press Enter to Continue...";
          getch();
      }
      break;

      case 7:{
          system("CLS");
          ///Igga Febrian Virgiani (1301194283)///
          cout<<"*===========Menghapus Data Lotre====================*"<<endl;
          cout<<"Masukan ID Lotre : ";
          cin>>s;
          findElm_C(LC,s);
          address_child K = first(LC);
          while ( K != NULL && info(K).ID != s){
            deleteFirst(LC,K);
          }

      }
      break;

      case 8: {
          system("CLS");
          ///Igga Febrian Virgiani (1301194283)///
        cout<<"*=============Menghapus Data Pembeli===================*"<<endl;
        cout<<"Masukan ID Pembeli :  ";
        cin>>q;
        findElm(LP,q)
        address_parent M;
        deleteFirstParent(LP,M);
      }
      break;

      case 9:{
          system("CLS");
          ///Igga Febrian Virgiani (1301194283)///
        cout<<"*==============Pengumuman Pemenang===================*"<<endl;
        cout<<"Pemenangnya adalah: ";
        cout<<s;
        s = randomPemenang();
        getch();
      }
      break;


    }





    }while (menu != 0);

    return 0;
}
