#include <iostream>
//include <cstdlib> merupakan suatu liblary di cpp untuk menggunakan clear screen (CLS)
#include <cstdlib>
using namespace std;


// ini adalah tampilan awal yang menggunakan void 
void pembuat(){
    cout<<"________________________________________________"<<endl;
    cout<<"=                  Dibuat Oleh                 ="<<endl;
    cout<<"________________________________________________"<<endl;
    cout<<"\nNama \t\t: Ananta yusra Putra Akmal"<<endl;
    cout<<"NIM \t\t: 2109106024"<<endl;
    cout<<"Kelas \t\t: Informatika A 2021"<<endl;
    cout<<"Praktikum \t: APL Posttest 3"<<endl;
    cout<<"________________________________________________\n\n"<<endl;
}
// ini adalah tampilan awal yang menggunakan void
void program(){
    cout<<"\n\n================================================"<<endl;
    cout<<"=          Program Kalkulator Sederhana        ="<<endl;
    cout<<"================================================"<<endl;

    cout<<""<<endl;
}
// ini adalah tampilan menu operasi yang menggunakan void
void menu_operasi(){
    cout<<"a. Perkalian"<<endl;
    cout<<"b. Pembagian"<<endl;
    cout<<"c. Pertambah"<<endl;
    cout<<"d. Pengurangan"<<endl;
    cout<<"e. Sisa Bagi (Modulus)"<<endl;
}
// ini adalah tampilan awal untuk menu operasi perkalian yang menggunakan void
void tambahh(){
    cout<<"================================================"<<endl;
    cout<<"=                   Pertambahan                ="<<endl;
    cout<<"================================================\n"<<endl;
}
// ini adalah tampilan awal untuk menu operasi pengurangan yang menggunakan void
void kurangg(){
    cout<<"================================================"<<endl;
    cout<<"=                   Pengurangan                ="<<endl;
    cout<<"================================================\n"<<endl;
}
// ini adalah tampilan awal untuk menu operasi pembagian yang menggunakan void
void bagii(){
    cout<<"================================================"<<endl;
    cout<<"=                    Pembagian                 ="<<endl;
    cout<<"================================================\n"<<endl;
}
// ini adalah tampilan awal untuk menu operasi pembagian yang menggunakan void
void kalii(){
    cout<<"================================================"<<endl;
    cout<<"=                    Perkalian                 ="<<endl;
    cout<<"================================================\n"<<endl;
}
// ini adalah tampilan awal untuk menu operasi perkalian yang menggunakan void
void moduluss(){
    cout<<"================================================"<<endl;
    cout<<"=                     Modulus                  ="<<endl;
    cout<<"================================================\n"<<endl;
}

// ini adalah overloading operasi 2 variabel dan 3 variabel 
int kali(int angka1, int angka2) {
    return angka1 * angka2;
}

int kali(int angka1, int angka2, int angka3) {
    return angka1 * angka2 * angka3;
}

int tambah(int angka1, int angka2) {
    return angka1 + angka2;
}

int tambah(int angka1, int angka2, int angka3) {
    return angka1 + angka2 + angka3;
}

int kurang(int angka1, int angka2) {
    return angka1 - angka2;
}

int kurang(int angka1, int angka2, int angka3) {
    return angka1 - angka2 - angka3;
}

int bagi(int angka1, int angka2){
    return angka1 / angka2;
}

int bagi(int angka1, int angka2, int angka3) {
    return angka1 / angka2 / angka3;
}

int sisabagi(int angka1, int angka2) {
    return angka1 % angka2;
}

int sisabagi(int angka1, int angka2, int angka3) {
    return angka1 % angka2 % angka3;
}

// body utama
int main(){
// deklarasikan variabel 
    char operasi;
    int pilihan;
    bool loop;
    string input;

    // looping 
    loop = true;
    while(loop){
    // memanggil void tampilan awal program
    pembuat();
    program();
    // Meminta input untuk angka pertama dan kedua
    cout<<"\t\t JUMLAH VARIABEL\n";
    cout<<"1. ( 2 variabel ):"<<endl;
    cout<<"2. ( 3 variabel ):"<<endl;
    cout<<"Masukkan pilihan 1/2 : "; cin>>pilihan;
    cout<<"'"<<endl; 
    // apabila pilihan 2 variabel 
    if (pilihan == 1){
        cout<<"\t\t OPERASI BILANGAN\n";
        //tampilan menu operasi 
        menu_operasi();
        // meminta inputan operasi mana yang ingin digunakan 
        cout<<"Masukkan operasi bilangan ( a, b, c, d, e) : ";
        cin>>operasi;
        cout<<"\n";
            //apabila operasi perkalian
            if (operasi == 'a'){
                // deklarasikan variabel inputan angka 1 dan angka 2
                int angka1, angka2;
                //menampilkan tampilan awal 
                kalii();
                //meminta inputan angka 1 dan ngka ke 2 
                cout<<"Masukkan bilangan pertama:";
                cin>>angka1;
                cout<<"Masukkan bilangan kedua:";
                cin>>angka2;
                {
                //perhitungan menggunakan overloading dan menampilkan hasil perhitungan 
                cout<<"hasil dari : "<< angka1 << " * "<<angka2<<" = "<< kali(angka1, angka2)<<endl;
                }}

            //apabila operasi pembagian
            if (operasi == 'b'){
                // deklarasikan variabel inputan angka 1 dan angka 2
                int angka1, angka2;
                //menampilkan tampilan awal 
                bagii();
                //meminta inputan angka 1 dan ngka ke 2 
                cout<<"Masukkan bilangan pertama:";
                cin>>angka1;
                cout<<"Masukkan bilangan kedua:";
                cin>>angka2;
                {
                //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
                cout<<"hasil dari : "<< angka1 << " / "<<angka2<<" = "<< bagi(angka1, angka2)<<endl;
                }}
                
            //apabila operasi pertambahan 
            if (operasi == 'c'){
                // deklarasikan variabel inputan angka 1 dan angka 2
                int angka1, angka2;
                //menampilkan tampilan awal
                tambahh();
                //meminta inputan angka 1 dan ngka ke 2 
                cout<<"Masukkan bilangan pertama:";
                cin>>angka1;
                cout<<"Masukkan bilangan kedua:";
                cin>>angka2;
                {
                //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
                cout<<"hasil dari : "<< angka1 << " + "<<angka2<<" = "<< tambah(angka1, angka2)<<endl;
                }}
                
            //apabila operasi pengurangan
            if (operasi == 'd'){
                // deklarasikan variabel inputan angka 1 dan angka 2
                int angka1, angka2;
                //menampilkan tampilan awal
                kurangg();
                //meminta inputan angka 1 dan ngka ke 2 
                cout<<"Masukkan bilangan pertama:";
                cin>>angka1;
                cout<<"Masukkan bilangan kedua:";
                cin>>angka2;
                {
                //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
                cout<<"hasil dari : "<< angka1 << " - "<<angka2<<" = "<< kurang(angka1, angka2)<<endl;
                }}
                
            //apabila operasi modulus 
            if (operasi == 'e'){
                // deklarasikan variabel inputan angka 1 dan angka 2
                int angka1, angka2;
                //menampilkan tampilan awal
                moduluss();
                //meminta inputan angka 1 dan ngka ke 2 
                cout<<"Masukkan bilangan pertama:";
                cin>>angka1;
                cout<<"Masukkan bilangan kedua:";
                cin>>angka2;
                {
                //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
                cout<<"hasil dari : "<< angka1 << " % "<<angka2<<" = "<< sisabagi(angka1, angka2)<<endl;
                }}
        //perulangan di 2 variabel 
        while(true){
            cout<<"\n________________________________________________"<<endl;
            cout<<"\n Gunakan kembali? (y/t) : "
                <<"\n > ";
            cin>>input;
            if(input=="y"){
                break;
            }
            else if(input=="t"){
                loop = false;
                break;
            }
            else{
                cout<<"\n Input salah coba lagi! ";
            } 
        //clear screen output           
        }system("CLS");
    }

    // apabila pilihan 3 variabel
    if (pilihan == 2){
        //tampilan menu operasi
        cout<<"\t\t OPERASI BILANGAN\n";
        menu_operasi();
        // meminta inputan operasi mana yang ingin digunakan 
        cout<<"Masukkan operasi bilangan ( a, b, c, d, e) : ";
        cin>> operasi;
        //apabila operasi perkalian
        if (operasi == 'a'){
            // deklarasikan variabel inputan angka 1 dan angka 2 dan angka3
            int angka1, angka2, angka3;
            //menampilkan tampilan awal
            kalii();
            //meminta inputan angka 1, 2 dan 3
            cout<<"Masukkan bilangan pertama:";
            cin>>angka1;
            cout<<"Masukkan bilangan kedua:";
            cin>>angka2;
            cout<<"Masukkan bilangan ketiga:";
            cin>>angka3;
            {
            //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
            cout<<"hasil dari : "<< angka1 << " * "<< angka2 <<" * "<< angka3 <<" = "<< kali(angka1, angka2, angka3) <<endl;
            }}
            
        //apabila operasi pembagian
        if (operasi == 'b'){
            // deklarasikan variabel inputan angka 1 dan angka 2 dan angka3
            int angka1, angka2, angka3;
            //menampilkan tampilan awal
            bagii();
            //meminta inputan angka 1, 2 dan 3
            cout<<"Masukkan bilangan pertama:";
            cin>>angka1;
            cout<<"Masukkan bilangan kedua:";
            cin>>angka2;
            cout<<"Masukkan bilangan ketiga:";
            cin>>angka3;
            {
            //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
            cout<<"hasil dari : "<< angka1 << " / "<< angka2 <<" / "<< angka3 <<" = "<< bagi(angka1, angka2, angka3) <<endl;
            }}
            
        //apabila operasi pertambahan 
        if (operasi == 'c'){
            // deklarasikan variabel inputan angka 1 dan angka 2 dan angka3
            int angka1, angka2, angka3;
            //menampilkan tampilan awal
            tambahh();
            //meminta inputan angka 1, 2 dan 3
            cout<<"Masukkan bilangan pertama:";
            cin>>angka1;
            cout<<"Masukkan bilangan kedua:";
            cin>>angka2;
            cout<<"Masukkan bilangan ketiga:";
            cin>>angka3;
            {
            //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
            cout<<"hasil dari : "<< angka1 << " + "<< angka2 <<" + "<< angka3 <<" = "<< tambah(angka1, angka2, angka3) <<endl;
            }}
            
        //apabila operasi pengurangan 
        if (operasi == 'd'){
            // deklarasikan variabel inputan angka 1 dan angka 2 dan angka3
            int angka1, angka2, angka3;
            //menampilkan tampilan awal
            kurangg();
            //meminta inputan angka 1, 2 dan 3
            cout<<"Masukkan bilangan pertama:";
            cin>>angka1;
            cout<<"Masukkan bilangan kedua:";
            cin>>angka2;
            cout<<"Masukkan bilangan ketiga:";
            cin>>angka3;
            {
            //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
            cout<<"hasil dari : "<< angka1 << " - "<< angka2 <<" - "<< angka3 <<" = "<< kurang(angka1, angka2, angka3) <<endl;
            }}
            
        //apabila operasi modulus
        if (operasi == 'e'){
            // deklarasikan variabel inputan angka 1 dan angka 2 dan angka3
            int angka1, angka2, angka3;
            //menampilkan tampilan awal
            moduluss();
            //meminta inputan angka 1, 2 dan 3
            cout<<"Masukkan bilangan pertama:";
            cin>>angka1;
            cout<<"Masukkan bilangan kedua:";
            cin>>angka2;
            cout<<"Masukkan bilangan ketiga:";
            cin>>angka3;
            {
            //perhitungan menggunakan overloading dan menampilkan hasil perhitungan
            cout<<"hasil dari : "<< angka1 << " % "<< angka2 <<" % "<< angka3 <<" = "<< sisabagi(angka1, angka2, angka3) <<endl;
            }}
        
        //perulangan di 3 variabel 
        while(true){
            cout<<"\n________________________________________________"<<endl;
            cout<<"\n Gunakan kembali? (y/t) : "
                <<"\n > ";
            cin>>input;
            if(input=="y"){
                break;
            }
            else if(input=="t"){
                loop = false;
                break;
            }
            else{
                cout<<"\n Input salah coba lagi!"<<endl;
            }
        //clear screen (CLS)
        }system("CLS");
    }
}}