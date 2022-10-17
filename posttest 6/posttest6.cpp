#include "iostream"
#include "string"
#include "algorithm"
#include "fstream"
#include "conio.h"
#include "stdlib.h"
#include "sstream"
using namespace std;

fstream myfile;

// struct untuk menyimpan data tujuan dan jumlah bungkusan 
struct Catering {
    string tujuan;
    int bungkusan;
};

// pendeklarasian variabel total dan catering, caterings
int total = 0;
Catering caterings[5];

//fungsi bolean pengurutan descending tujuan 
bool comparetujuan(Catering b1, Catering b2) {
	if(b1.tujuan < b2.tujuan) {
		return true;
	} return false;
}
//fungsi bolean pengurutan ascending tujuan 
bool comparetujuan1(Catering b1, Catering b2) {
	if(b1.tujuan > b2.tujuan) {
		return true;
	} return false;
}
//fungsi bolean pengurutan descending bungkusan 
bool comparebungkusan(Catering b1, Catering b2) {
	if(b1.bungkusan < b2.bungkusan) {
		return true;
	} return false;
}
//fungsi bolean pengurutan ascending bungkusan 
bool comparebungkusan1(Catering b1, Catering b2) {
	if(b1.bungkusan > b2.bungkusan) {
		return true;
	} return false;
}


// fungsi global input data 
void inputData(Catering caterings[], int jumlah){
    system("cls");
    Catering catering;
    
    // MENGAMBIL INPUTAN USER
    cout<< "\n\t\tTAMBAH DATA PESANAN CATERING" << endl
    << "===================================================" << endl;
    cout << "Masukan Tujuan Pengantaran : "; fflush(stdin);
    getline(cin,catering.tujuan);
    cout << "Masukan Jumlah Bungkusan : "; cin >> catering.bungkusan;

    // APPEND DATA KE ARRAY
    caterings[total] = catering;
    cout << "\nBerhasil menambah kan !" <<endl;
    total++;
    
    myfile.open("data.txt", ios::out);
    for (int i = 0; i < jumlah; i++)
    {
        myfile << caterings[i].tujuan << "," << caterings[i].bungkusan << endl;
    }
    
    myfile.close();
}

// fungsi global melihat/menampilkan data
void readData(Catering caterings[], int jumlah){
    system("cls");
    cout<< "\n\t\tSELURUH DATA PESANAN CATERING" << endl
        << "===================================================" << endl;
    if(total == 0) {
        cout << "Data kosong...\n";
    } else {
        for (int index = 0; index < total; index++) {
        Catering catering = caterings[index];
        cout
            << "Data Ke-" << index + 1 << endl
            << "Tujuan Pengantaran: " << catering.tujuan << endl
            << "Jumlah Bungkusan: " << catering.bungkusan << endl
            << endl;
        }
    }
    myfile.open("data.txt", ios::out);
    for (int i = 0; i < jumlah; i++)
    {
        myfile << caterings[i].tujuan << "," << caterings[i].bungkusan << endl;
    }
    
    myfile.close();
}

// fungsi global memperbaharui data 
void updateData(Catering caterings[], int jumlah){
    system("cls");
    int index;
    Catering catering;
    cout<< "\n\t\tUBAH DATA PESANAN CATERING" << endl
        << "===================================================" << endl;

    cout << "Masukkan urutan data (" << total << ") : "; cin >> index;

    // CEK APAKAH INPUTAN BUKAN 0 DAN INPUTAN TIDAK MELEBIHI TOTAL DATA
    if(index != 0 && index <= total) {
    // AMBIL DATA YANG DIPILIH
    catering = caterings[index - 1];

    // INPUTAN DATA TERBARU
    cout << "Masukan Tujuan Pengantaran [" << catering.tujuan << "] : "; fflush(stdin);
    getline(cin,catering.tujuan);
    cout << "Masukan Jumlah Bungkusan [" << catering.bungkusan << "] : "; cin >> catering.bungkusan;

    // UPDATE DATA
    caterings[index - 1] = catering;
    cout << "\nBerhasil mengubah " << catering.tujuan <<endl;
    } else {
    cout << "\nData tidak ada!";
    }system("cls");

    myfile.open("data.txt", ios::out);
    for (int i = 0; i < jumlah; i++)
    {
        myfile << caterings[i].tujuan << "," << caterings[i].bungkusan << endl;
    }
    
    myfile.close();
}

// fungsi global menghapus data 
void deleteData(Catering caterings[], int jumlah){
    system("cls");
    int index;
    cout<< "\n\t\tHAPUS DATA PESANAN CATERING" << endl
        << "===================================================" << endl;
    cout << "Masukkan urutan data (1-" << total << ") : "; cin >> index;

    // CEK APAKAH INPUTAN BUKAN 0 DAN INPUTAN TIDAK MELEBIHI TOTAL DATA
    if(index != 0 && index <= total) {

    // MENGHAPUS DATA DENGAN MENINDIH DATA YANG DIHAPUS DENGAN DATA SESUDAHNYA
    for (int i = index - 1; i < total; ++i) {
        caterings[i] = caterings[i + 1];
    }
    cout << "\nBerhasil menghapus !";

    // MENGURANGI TOTAL DATA
    total--;
    } else {
    cout << "\nData tidak ada!";
    }system("cls");

    myfile.open("data.txt", ios::out);
    for (int i = 0; i < jumlah; i++)
    {
        myfile << caterings[i].tujuan << "," << caterings[i].bungkusan << endl;
    }
    
    myfile.close();
}

//void fungsi descending
void descending(){
    cout << "\n   ---------------------------------------------";
    cout << "\n   |       >> Program Pengurutan Data <<       |";
    cout << "\n   |           >> Secara Descending<<          |";
    cout << "\n   ---------------------------------------------\n";
        //deklarasi vaiabel sorting atribut
        int pilihan1;
        //input memilih sorting atribut
        cout<<"\t\t SORTING ATRIBUT\n";
        cout<<"1. Tujuan "<<endl;
        cout<<"2. Bungkusan "<<endl;
        cout<<"Masukkan Pilihan : "; cin>>pilihan1;
        cout<<"'"<<endl;
        //piihan 1 sorting atribut Tujuan
        if (pilihan1 == 1){
            //fungsi ngesorting data struck
            sort(caterings, caterings+5, comparetujuan);
            cout<< "Tujuan : \n"<<endl;
            //menampilkan hasil sorting
            for(int i = 0; i<5; i++) { 
            cout << caterings[i].tujuan <<endl;		
            }	
            }
        //piihan 2 sorting atribut bungkusan 
        if (pilihan1 == 2){
            //fungsi ngesorting data struck
            sort(caterings, caterings+5, comparebungkusan);
            cout<< "Bungkusan : \n"<<endl;
            //menampilkan hasil sorting
            for(int i = 0; i<5; i++) { 
            cout << caterings[i].bungkusan <<endl;		
            }	
            }
}
//void fungsi ascending
void ascending(){
    cout << "\n   ---------------------------------------------";
    cout << "\n   |       >> Program Pengurutan Data <<       |";
    cout << "\n   |           >> Secara Ascending <<          |";
    cout << "\n   ---------------------------------------------\n";
        //deklarasi vaiabel sorting atribut
        int pilihan1;
        //input memilih sorting atribut
        cout<<"\t\t SORTING ATRIBUT\n";
        cout<<"1. Tujuan "<<endl;
        cout<<"2. Bungkusan "<<endl;
        cout<<"Masukkan Pilihan : "; cin>>pilihan1;
        cout<<"'"<<endl;
        //piihan 1 sorting atribut Tujuan
        if (pilihan1 == 1){
            //fungsi ngesorting data struck
            sort(caterings, caterings+5, comparetujuan1);
            cout<< "Tujuan : \n"<<endl;
            //menampilkan hasil sorting
            for(int i = 0; i<5; i++) { 
            cout << caterings[i].tujuan <<endl;		
            }	
            }	
        //piihan 2 sorting atribut bungkusan
        if (pilihan1 == 2){
            //fungsi ngesorting data struck
            sort(caterings, caterings+5, comparebungkusan1);
            cout<< "Bungkusan : \n"<<endl;
            //menampilkan hasil sorting
            for(int i = 0; i<5; i++) { 
            cout << caterings[i].bungkusan <<endl;		
            }	
            }	
}

void searching(){
        //deklarasi vaiabel searching atribut
        int pilihan1;
        //input memilih searching atribut
        cout<<"\t\t SORTING ATRIBUT\n";
        cout<<"1. Bungkusan "<<endl;
        cout<<"2. Tujuan "<<endl;
        cout<<"Masukkan Pilihan : "; cin>>pilihan1;
        cout<<"'"<<endl;
        //piihan 1 searching atribut bungkusan (integer)
        if (pilihan1 == 1){
            cout << "===================================================" << endl;
            cout << "            Searching Berdasarkan Bungkusan        " << endl;
            cout << "===================================================" << endl;
            // deklarasi variabel 
            // k = data yang ingin di cari di data bungkusan
            // i = nilai di dalam proses searching
            int i, k;
            bool found;
            cout<<"\nMasukan Jumlah Bungkusan yang dicari = ";
            cin >>k;
            // proses searching
            found =false;
            i=0;
            while ((i<10)&(!found))
            {
                if (caterings[i].bungkusan==k)
                found=true;
                else
                i=i+1;
            }
            if(found){
            //output dari searching 
            cout<<"\n"<<endl;
            cout<<"\t\tDATA DI TEMUKAN"<<endl;
            cout<<"Bungkusan : "<<caterings[i].bungkusan <<endl;
            cout<<"Tujuan    : "<<caterings[i].tujuan <<endl;
            }
            else
            cout<<"\nBungkusan "<<k<<" tidak ada dalam data\n";
            }	
        //piihan 2 searching atribut tujuan (string)
        if (pilihan1 == 2){
            cout << "===================================================" << endl;
            cout << "             Searching Berdasarkan Tujuan          " << endl;
            cout << "===================================================" << endl;
            // deklarasi variabel 
            // k = data yang ingin di cari di data bungkusan
            // i = nilai di dalam proses searching
            int i; 
            string k;
            bool found;
            cout<<"\nMasukan Tujuan yang di cari = ";
            cin >>k;
            // proses searching
            found =false;
            i=0;
            while ((i<10)&(!found))
            {
                if (caterings[i].tujuan==k)
                found=true;
                else
                i=i+1;
            }
            if(found){
            //output dari searching 
            cout<<"\n"<<endl;
            cout<<"\t\tDATA DI TEMUKAN"<<endl;
            cout<<"Bungkusan : "<<caterings[i].bungkusan <<endl;
            cout<<"Tujuan    : "<<caterings[i].tujuan <<endl;
            }
            else
            cout<<"\nTujuan "<< k <<" tidak ada dalam data\n";
            }	
}

void refresh(Catering caterings[], int jumlah){
    Catering catering;
    myfile.open("data.txt", ios::out);
    for (int i = 0; i < jumlah; i++)
    {
        myfile << caterings[i].tujuan << "," << caterings[i].bungkusan << endl;
    }
    
    myfile.close();
}
// void tampilan awal 
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

int main() {
    myfile.open("data.txt", ios::out);
    // jika file nya belum ada maka dibuatkan
    if (!myfile.is_open())
    {
        // penjelasan mode trunc ada dimodul
        myfile.open("data.txt", ios::trunc);
        myfile.close();
    }
    myfile.close();


    system("cls");
    string x;
    pembuat();
    cout << "\n\n";
    // tampilan awal 
    cout << "===================================================" << endl;
    cout << "             Program Data Pesanan Catering         " << endl;
    cout << "===================================================" << endl;

    // tampilan menu 
    menu:
    cout << "===================================================" << endl;
    cout << "                     MENU UTAMA                    " << endl;
    cout << "===================================================" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Tampilkan Seluruh Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Sorting Desscending" << endl;
    cout << "6. Sorting Ascending" << endl;
    cout << "7. Searching" << endl;
    cout << "8. REFRESH" << endl;
    cout << "9. Exit" << endl;
    cout << endl;

    cout << "Pilih Menu [1-8]: ";
    cin >> x;

    // pilihan 1 sebagai input data 
    if (x == "1"){
        inputData(caterings,total);
        goto menu;
    }
    // pilihan 2 sebagai melihat/menampilkan data 
    else if ( x=="2"){
        readData(caterings,total);
        goto menu;
    }
    // pilihan 3 sebagai update data 
    else if (x == "3"){
        updateData(caterings,total);
        goto menu;
    }
    // pilihan 4 sebagai hapus data 
    else if (x== "4") {
        deleteData(caterings,total);
        system("cls");
        cout << "Penghapusan Data Sukses" << endl;
        goto menu;
    }
    // pilihan 5 sebagai sorting descending
    else if (x== "5") {
            system("cls");
            descending();
            cout << "\nPengurutan Selesai" << endl;
        goto menu;
    }
    // pilihan 6 sebagai ascending
    else if (x== "6") {
            system("cls");
            ascending();
            cout << "\nPengurutan Selesai" << endl;
        goto menu;
    }
    // 
    // pilihan 7 sebagai searching
    else if (x== "7") {
            system("cls");
            searching();
            cout << "\nPencarian Selesai\n" << endl;
        goto menu;
    }
    else if (x== "8") {
        system("cls");
        refresh(caterings,total);
    goto menu;
    }
    // pilihan 8 sebagai exit program
    else if (x == "9") {
        system("cls");
        atexit;
    }
    
    // pilihan selain 1-8
    else {
        system ("cls");
        cout << "\nInput Tidak Valid !!! \n" << endl;
        goto menu;
    } 
	return 0;
}



