#include<iostream>
#include<string.h>
using namespace std;


struct data{
    string nama;
    int no;
};
struct data satu[10];
struct data dua [10];
struct data swipe;
int n;
void sorting (){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1;j++){
            if (satu[j].no > satu[j+1].no){
                swipe = satu[j];
                satu[j]=satu[j+1];
                satu[j+1]=swipe;
            }
        }
    }
        for (int i=0;i<n;i++){
        cout <<"\n======================"<<endl;
        cout <<"\n\nnama :"<<satu[i].nama;
        cout <<"\nnomor :" <<satu[i].no  ;
    }
}
int main(){
    cout << "jumlah inputan ="; cin >>n;
    for (int i=0;i<n;i++){
        cout << "\nmasukan nama :"; fflush(stdin);getline(cin,satu[i].nama);
        cout << "\n nomor       :"; cin >> satu[i].no;
        dua[i]=satu[i];
    }
    cout <<"\n\n======================================";
    cout << "\ndata yang belum di sort\n" ;
    cout <<"======================================\n";
    for (int i=0;i<n;i++){
        cout <<"\n======================"  ;
        cout <<"\nnama :"<<dua[i].nama     ;
        cout <<"\nnomor :" <<dua[i].no     ;
    } 
    cout << "\n\n======================================";
    cout << "\ndata yang sudah di sort \n";
    cout << "======================================\n";
    sorting();
    cout <<"\n\n======================================";
    cout << "\ndata yang belum di sort\n" ;
    cout <<"======================================\n";
    for (int i=0;i<n;i++){
        cout <<"\n======================";
        cout <<"\nnama :"<<dua[i].nama;
        cout <<"\nnomor :" <<dua[i].no  ;
    }
}
