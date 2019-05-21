#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;

void korps();
void alamat();
void trims();
void line();

long jl(long byk, long hrg);
long ttl(long tot, long hrgjl);
long sisa( long tn, long tl);

main()
{
system("color 0a");
int i, x, y, a=0, b=0, c=0, hr, thn;
char kasir[30], bln[15];
long total, tunai, kembali;

for (int i=0;i<=100;i++)
{
    cout<<endl<<"Loading..."<<i<<"%"<<endl;
    system("cls");

}
cout<<"LOADING COMPLETE"<<endl;
system("cls");
struct
 {
 char kode[10], nama[20];
 long banyak, harga, jual;
 } produk[50];

korps();
alamat();
line();
time_t t=time(0);
tm*now = localtime(&t);cout<< (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday;
cout<<"\tNama Kasir\t: ";
cin.getline(kasir,30);
line;

ne:
total=0;
a=a+1;
b=1;
c=1;
reply:
korps();
cout<<endl;
cout<<"Nomor transaksi\t: No. 00"<<a<<endl;
cout<<"Banyak beli jenis produk\t: ";cin>>y;
if (y<=10)
 goto next;
else
 goto reply;
next:
cout<<endl;
cout<<"kode produk\t: PCL untuk Paracetamol\n\t\t  VIT untuk Vitamin\n\t\t  OBH untuk OBH batuk\n\t\t  PST untuk Ponstan\n\t\t  BLS untuk Balsem"<<endl;
cout<<"\t\t  MYA untuk Minyak Angin\n\t\t  TKA untuk Tolak Angin\n\t\t  BTD untuk Betadine\n\t\t  ALK untuk Alkohol\n\t\t  MKP untuk Minyak Kayu Putih"<<endl;
cout<<endl;
line();
for (x=1;x<=y;x++)
 {
   cout<<"Jenis beli produk ke- "<<b++<<endl;
   cout<<"Masukkan kode produk\t\t: ";cin>>produk[x].kode;
   cout<<"Jumlah beli produk\t\t: ";cin>>produk[x].banyak;
   line();
   if (!strcmp(produk[x].kode,"PCL")||!strcmp(produk[x].kode,"pcl"))
    {
      strcpy(produk[x].nama,"Paracetamol");
      produk[x].harga=2000;
      }
   else if (!strcmp(produk[x].kode,"VIT")||!strcmp(produk[x].kode,"vit"))
    {
      strcpy(produk[x].nama,"Vitamin");
      produk[x].harga=10000;
      }
   else if (!strcmp(produk[x].kode,"OBH")||!strcmp(produk[x].kode,"obh"))
    {
      strcpy(produk[x].nama,"OBH batuk");
      produk[x].harga=16000;
      }

   else if (!strcmp(produk[x].kode,"PST")||!strcmp(produk[x].kode,"pst"))
    {
      strcpy(produk[x].nama,"Ponstan");
      produk[x].harga=3000;
      }
   else if (!strcmp(produk[x].kode,"BLS")||!strcmp(produk[x].kode,"bls"))
    {
      strcpy(produk[x].nama,"Balsem");
      produk[x].harga=6000;
      }
   else if (!strcmp(produk[x].kode,"MKP")||!strcmp(produk[x].kode,"mkp"))
    {
      strcpy(produk[x].nama,"Minyak kayu putih");
      produk[x].harga=8000;
      }
   else if (!strcmp(produk[x].kode,"MYA")||!strcmp(produk[x].kode,"mya"))
    {
      strcpy(produk[x].nama,"Minyak angin");
      produk[x].harga=11000;
      }
   else if (!strcmp(produk[x].kode,"TKA")||!strcmp(produk[x].kode,"tka"))
    {
      strcpy(produk[x].nama,"Tolak angin");
      produk[x].harga=3000;
      }
   else if (!strcmp(produk[x].kode,"BTD")||!strcmp(produk[x].kode,"btd"))
    {
      strcpy(produk[x].nama,"Betadine");
      produk[x].harga=3000;
      }
   else if (!strcmp(produk[x].kode,"ALK")||!strcmp(produk[x].kode,"alk"))
    {
      strcpy(produk[x].nama,"Alkohol 70%");
      produk[x].harga=20000;
      }
   else
    {
      strcpy(produk[x].nama,"??????");
      produk[x].harga=0;
  }
   }
system("cls");
korps();
alamat();
cout<<endl;
line();
cout<< (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday;
cout<<"\t\t" <<setw(8)<<kasir<<"/"<<"NMH00"<<a<<endl;
line();
cout<<"No. Nama\t\tharga\tbanyak\tharga"<<endl;
cout<<"    produk\t\tproduk\tbeli\tjual"<<endl;
cout<<endl;
for (x=1;x<=y;x++)
 {
   cout<<setiosflags(ios::left)<<setw(4)<<c++;
   cout<<setiosflags(ios::left)<<setw(20)<<produk[x].nama;
   cout<<setiosflags(ios::left)<<setw(8)<<produk[x].harga;
   cout<<setiosflags(ios::left)<<setw(8)<<produk[x].banyak;
   produk[x].jual=jl(produk[x].harga,produk[x].banyak);
   cout<<setiosflags(ios::right)<<setw(4)<<produk[x].jual<<endl;
   total=ttl(total,produk[x].jual);
 }
line();
cout<<"\t\t\ttotal\t      : "<<total<<endl;
cout<<"\t\t\ttunai\t      : ";cin>>tunai;
kembali=sisa(tunai,total);
cout<<"\t\t\tkembali\t      : "<<kembali;
cout<<endl<<endl;
ofstream out ("struk.txt");
out<< "Nama kasir: "<<kasir<<total<<endl<<tunai<<endl<<kembali<<endl;
trims();
getch();

char lagi;
cout<<"tindak lanjut! pilih!\n";
cout<<"N= transaksi baru\n";
cout<<"X= close\n";
cout<<"==>>";cin>>lagi;
if (lagi=='N'||lagi=='n')
 {
   goto ne;
 }
else
 {
   goto ex;
   }
ex:
getch();
}
void korps()
 {
 cout<<"\t\tBLACKPINK! HEALTHY LIFE\n";
 }
void alamat()
 {
 cout<<"\t\tJl. Karawang Barat no. 1\n";
 cout<<"                 Cabang Karawang\n";
 }
 void trims()
 {
 cout<<"                   TERIMAKASIH\n";
 cout<<"                Semoga Lekas Sembuh\n";
 cout<<"       Info Lengkap : www.blaqpinq.com\n";
 }
 void line()
 {
 cout<<"___________________________________________________\n";
 }
long jl(long byk, long hrg)
 {
 return (byk*hrg);
 }

long ttl(long tot, long hrgjl)
 {
 return (tot+hrgjl);
 }

long sisa( long tn, long tl)
 {
 return (tn-tl);
 }
