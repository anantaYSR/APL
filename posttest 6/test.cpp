#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// terdapat 3 tipe data
// ifstream : berfungsi untuk membaca file
// ofstream : berfungsi untuk menulis kedalam file
//            (kalau file gak ada nanti dibuatkan automatis)
// fstream  : dapat membaca,menulis,membuat file

// variabel global
fstream myFile;

struct Barang
{
    string nama;
    int stok, harga;
};

void readFile(Barang data[]);
void tambahBarang(Barang data[]);
void writeFile(Barang data[], int jumlah);
void openFile();

int main()
{
    openFile();
    Barang dataBarang[5];
    tambahBarang(dataBarang);
    writeFile(dataBarang, 5);
    readFile(dataBarang);

    return 0;
}
void openFile()
{
    myFile.open("barang.csv", ios::out);
    // jika file nya belum ada maka dibuatkan
    if (!myFile.is_open())
    {
        // penjelasan mode trunc ada dimodul
        myFile.open("barang.csv", ios::trunc);
        myFile.close();
    }
    myFile.close();
}
void readFile(Barang data[])
{
    // Membaca file eksternal
    // ifstream myFile;
    myFile.open("barang.csv", ios::in);
    int i = 0;
    string stok, harga;
    while (!myFile.eof())
    {
        // myFile >> kata;
        // 016
        getline(myFile, data[i].nama, ',');
        getline(myFile, stok, ',');
        getline(myFile, harga, '\n');
        // untuk conver string ke tipe data lain
        stringstream stokString(stok);
        stringstream hargaString(harga);
        stokString >> data[i].stok;
        hargaString >> data[i].harga;
        if (myFile.eof())
        {
            break;
        }
        cout << "data ke - " << i + 1 << endl;
        cout << "Nama  : " << data[i].nama << endl;
        cout << "Stok  : " << data[i].stok << endl;
        cout << "Harga : " << data[i].harga << endl;
        i++;
    }
    myFile.close();
}
void writeFile(Barang data[], int jumlah)
{
    // Menulis file eksternal
    // ofstream myFile;
    myFile.open("barang.csv", ios::out);
    for (int i = 0; i < jumlah; i++)
    {
        myFile << data[i].nama << "," << data[i].stok << "," << data[i].harga << endl;
    }
    myFile.close();
}
void tambahBarang(Barang data[])
{
    Barang data1;
    data1.nama = "kecap";
    data1.stok = 10;
    data1.harga = 10000;
    Barang data2;
    data2.nama = "jeruk";
    data2.stok = 20;
    data2.harga = 20000;
    Barang data3;
    data3.nama = "susu";
    data3.stok = 30;
    data3.harga = 30000;
    Barang data4;
    data4.nama = "teh";
    data4.stok = 40;
    data4.harga = 40000;
    Barang data5;
    data5.nama = "kopi";
    data5.stok = 50;
    data5.harga = 50000;
    data[0] = data1;
    data[1] = data2;
    data[2] = data3;
    data[3] = data4;
    data[4] = data5;
}