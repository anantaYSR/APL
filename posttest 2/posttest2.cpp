/*
Nama        : ananta yusra putra akmal 
NIM         : 2109106024
Kelas       : Informatika A 2021
Praktikum   : APL A1 responsi 2
*/

// Library 
#include<iostream>
#include<iomanip>
using namespace std;

// Tampilan awal menggunakan fungsi global (void)
void tampilan_awal(){
    cout << "\n\t\t\tMENAMPILKAN NILAI & ALAMAT ARRAY\n"<< endl;
    cout << "Nilai elemen dihitung dengan rumus : " << endl;
    cout << "\nNIM Akhir = 24" << endl;
    cout << "(24*x^2 + y^2)" << endl;
    cout << "====================================" << endl;
}
// Tampilan matriks menggunakan fungsi global (void)
void tampilan_matriks(){
    cout << "\tBENTUK MATRIKS 5x5" << endl;
    cout << "" << endl;
}
void tampilan_nilai_alamat(){
    cout << "====================================" << endl;
    cout << "       NILAI DAN ALAMAT ARRAY       \n\n" << endl;
}

// Fungsi utama
int main(){
    int a, b, x, y;
//fungsi a sebagai wadah pertama menampung matriks yang akan di hitung oleh rumus f(x,y) 
//fungsi b sebagai wadah kedua menampung matriks yang akan di hitung oleh rumus f(x,y) 
//fungsi x sebagai perhitungan dalam rumus f(x,y)  
//fungsi y sebagai perhitungan dalam rumus f(x,y)

// Deklarasi Array
    int Ananta_24[5][5];

// Loop nilai elemen 
    for (a = 0; a < 5; a++){
        for (b = 0; b < 5; b++){

            x = a;
            y = b;

// Rumus Fungsi f(x, y)
        Ananta_24[a][b] = ((24*x^2 + (x^x) - 1) - y*24);
            
        }
    }
tampilan_awal();
tampilan_matriks();

// Bentuk Matriks 5x5
    for (a = 0; a < 5; a++){
        for (b = 0; b < 5; b++){
            
            cout << setw(4) << Ananta_24[a][b]; 
        }
        cout << endl;
    }
tampilan_nilai_alamat();

// Loop output nilai & alamat
    for (a = 0; a < 5; a++){
        for (b = 0; b < 5; b++){
            
//Pointer
            int *ptr = Ananta_24[a];

            cout << "Pada Index ke   : " << a << "," << b <<  "\nMempunyai Nilai : " << *(ptr + b) << endl;
            cout << "Alamat : " << ptr + b << endl;
            cout << "=====================================\n" << endl;
        }
    }

    return 0;
}