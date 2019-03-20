/*Nama : Anugerah Prima Bagaskara
NPM : 140810180006
Tanggal Buat : 20/03/2019
Deskripsi : Linked List
*/
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct ElemtList{
	string nama;
	char bidang[30];
	int gaji;
	ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;


void createList(List& First){
	First=NULL;
}

void createElmt(pointer& pBaru){
	pBaru = new ElemtList;
	cout<<"Nama : ";getline(cin,pBaru->nama);
	cout<<"Bidang : ";cin>>pBaru->bidang;
	cout<<"Gaji : ";cin>>pBaru->gaji;
	pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First==pBaru;
	}
	else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void deleteFirst (List& First, pointer& pHapus){
	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if( First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else {
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void deleteLast(List&First, pointer&pHapus){
	pointer last,precLast;
	cout<<"Delete Last"<<endl;
	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}
	else{
		last=First;
		precLast=NULL;
		while(last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

void traversal(List First){
	int i=1;
	pointer pBantu;
	if(First==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		pBantu=First;
		do{
			cout<<"No. "<<(i)<<endl;
			cout<<"Nama : "<<pBantu->nama<<endl;
			cout<<"Bidang : "<<pBantu->bidang<<endl;
			cout<<"Gaji : "<<pBantu->gaji<<endl;
			pBantu = pBantu->next;
		}while(pBantu !=NULL);
	}
}

int main(){
 List Pegawai;
 pointer p;
 int pil,n;
 char loop='Y';
 do{
  system("CLS");
  cout<<"Banyak Data Pegawai : ";cin>>n;
  createList(Pegawai);
  for(int i=0; i<n; i++){
   cout<<"\nData Pegawai ke-"<<i+1<<endl;
   createElmt(p);
   insertLast(Pegawai,p);
  }
  do{
   system("CLS");
   cout<<"1. Buat Data Pegawai Baru di Awal\t4. Hapus Data Pegawai Paling Akhir\n";
   cout<<"2. Buat Data Pegawai Baru di Akhir\t5. Cetak Data Pegawai\n";
   cout<<"3. Hapus Data Pegawai Paling Awal\t6. Buat List Data Pegawai Baru\n";
   do{
    cin>>pil;
   }while(pil<1 || pil>6);
   switch(pil){
    case 1:
     createElmt(p);
     insertFirst(Pegawai,p);
     cout<<"\nData berhasil dibuat!\n";
     getch();
     break;
    case 2:
     createElmt(p);
     insertLast(Pegawai,p);
     cout<<"\nData berhasil dibuat!\n";
     getch();
     break;
    case 3:
     deleteFirst(Pegawai,p);
     cout<<"\nData berhasil dihapus!\n";
     getch();
     break;
    case 4:
     deleteLast(Pegawai,p);
     cout<<"\nData berhasil dihapus!\n";
     getch();
     break;
    case 5:
     traversal(Pegawai);
     cout<<"\nKembali ke menu? (Y/N) ";
     do{
      cin>>loop;
     }while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
     break;
    case 6:
     loop='x';
     break;
   }
  }while(loop=='Y' || loop=='y');
 }while(loop=='x');
}
