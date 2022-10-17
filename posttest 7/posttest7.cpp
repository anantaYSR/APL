#include "iostream"
#include "string"
#include "algorithm"
#include "fstream"
#include "conio.h"
#include "stdlib.h"
#include "sstream"
using namespace std;

//library untuk membuat, membaca dan mengubah file
fstream myfile;

// struct untuk menyimpan data tujuan dan jumlah bungkusan 
struct Catering {
    string tujuan;
    int bungkusan;
};

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

int getTotal() {
    int total = 0;
    string tmp;
    myfile.open("data.txt", ios::in);
    // AMBIL TOTAL
    while (getline(myfile, tmp)) {
        total++;
    };
    myfile.close();
    return total;
}
// fungsi global input data 
void inputData(){
    system("cls");
    Catering catering;
    
    // MENGAMBIL INPUTAN USER
    cout<< "\n\t\tTAMBAH DATA PESANAN CATERING" << endl
    << "===================================================" << endl;
    cout << "Masukan Tujuan Pengantaran : "; fflush(stdin);
    getline(cin,catering.tujuan);
    cout << "Masukan Jumlah Bungkusan : "; cin >> catering.bungkusan;

    //myfile open membuka data txt
    //data adalah nama file dalam bentuk txt
    myfile.open("data.txt", ios::app);

    //fungsi untuk menambahkan data kedalam struct Catering = tujuan dan bungkusan 
    myfile << catering.tujuan << ", " << catering.bungkusan << "\n";

    //menutup file setelah bagian void di jalan kan
    myfile.close();

    cout << "\nBerhasil menambah kan !" <<endl;
}


// fungsi global melihat/menampilkan data
void readData(){
// Membaca file eksternal
    // ifstream myFile;
    myfile.open("data.txt", ios::in);
    int i = 0;
    string bungkusan, tujuan;
    while (!myfile.eof())
    {
        // myFile >> kata;
        // 016
        getline(myfile, tujuan, ',');
        getline(myfile, bungkusan, '\n');
        // untuk conver string ke tipe data lain
        if (myfile.eof()) break;
        cout << "data ke - " << i + 1 << endl;
        cout << "Nama  : " << tujuan << endl;
        cout << "Stok  : " << bungkusan << endl;
        i++;
    }
    myfile.close();
}

    


// fungsi global memperbaharui data 
void updateData(){
    system("cls");
    int index;
    Catering new_catering;

    int total = getTotal();

    cout<< "\n\t\tUBAH DATA PESANAN CATERING" << endl
        << "===================================================" << endl;
    cout << "Masukkan urutan data (" << total << ") : "; cin >> index;
    // CEK APAKAH INPUTAN BUKAN 0 DAN INPUTAN TIDAK MELEBIHI TOTAL DATA
    if(index != 0 && index <= total) {
        // INPUTAN DATA TERBARU
        cout << "Masukan Tujuan Pengantaran: "; fflush(stdin);
        getline(cin,new_catering.tujuan);
        cout << "Masukan Jumlah Bungkusan: "; cin >> new_catering.bungkusan;

        // deklarasi variabel 
        int i = 1;
        string catering, bungkusan, tujuan;
        string val;

        myfile.open("data.txt", ios::in);

        // LOOPING DATA LAMA DAN MASUKKAN KE DALAM STRING val
        while (getline(myfile, catering)) {
            if(i == index) {
                val += new_catering.tujuan + "," + to_string(new_catering.bungkusan) + "\n";
            } else {
                stringstream line(catering);
                getline(line, tujuan, ',');
                getline(line, bungkusan, '\n');
                val += tujuan + "," + bungkusan + "\n";
            }
            i++;
        }
        myfile.close();
        // RESET DATA DAN MASUKKAN DATA BARU
        myfile.open("data.txt", ios::out | ios::trunc);
        myfile << val;
        myfile.close();


        cout << "\nBerhasil mengubah catering!" << endl;
    } else {
        cout << "\nData tidak ada!";
    }
    system("cls");

}

// // fungsi global menghapus data 
void deleteData(){
    system("cls");
    int index;

    int total = getTotal();

    cout<< "\n\t\tHAPUS DATA PESANAN CATERING" << endl
        << "===================================================" << endl;
    cout << "Masukkan urutan data (" << total << ") : "; cin >> index;
    // CEK APAKAH INPUTAN BUKAN 0 DAN INPUTAN TIDAK MELEBIHI TOTAL DATA
    if(index != 0 && index <= total) {
        int i = 1;
        string catering, bungkusan, tujuan;
        string val;

        myfile.open("data.txt", ios::in);

        // LOOPING DATA LAMA DAN MASUKKAN KE DALAM STRING val
        while (getline(myfile, catering)) {
            if(i != index) {
                stringstream line(catering);
                getline(line, tujuan, ',');
                getline(line, bungkusan, '\n');
                val += tujuan + "," + bungkusan + "\n";
            }
            i++;
        }
        myfile.close();
        // RESET DATA DAN MASUKKAN DATA BARU
        myfile.open("data.txt", ios::out | ios::trunc);
        myfile << val;
        myfile.close();


        cout << "\nBerhasil mengubah catering!" << endl;
    } else {
        cout << "\nData tidak ada!";
    }
    system("cls");
}
//void fungsi sorting
void sorting(){
    // deklarasi variabel
    int attr, type;
    Catering caterings[1000];

    //menampilkan tampilan
    cout << "\n   ---------------------------------------------";
    cout << "\n   |       >> Program Pengurutan Data <<       |";
    cout << "\n   ---------------------------------------------\n";
    
    //menampilkan tampilan
    cout<<"\t\t SORTING ATRIBUT\n";
    cout<<"1. Tujuan "<<endl;
    cout<<"2. Bungkusan "<<endl;
    cout<<"Masukkan Pilihan : "; cin>>attr;

    //menampilkan tampilan
    cout<<"\t\t TIPE SORTING\n";
    cout<<"1. Asc "<<endl;
    cout<<"2. Desc "<<endl;
    cout<<"Masukkan Pilihan : "; cin>>type;

    // membuka file data.txt
    myfile.open("data.txt", ios::in);
    //deklarasi variabel
    string tmp, bungkusan;
    int index = 0;
    Catering catering;
    // perulangan untuk mendapatkan nilai struc pada file data.txt
    while (getline(myfile, tmp)) {
        
        stringstream line(tmp);
        getline(line, catering.tujuan, ',');
        getline(line, bungkusan, '\n');

        catering.bungkusan = stoi(bungkusan);
        caterings[index] = catering;
        index++;
    }
    //menutup file data.txt
    myfile.close();

    //deklarasi variabel 
    int total = getTotal();
    // perulangan untuk membandingkan data lama dan data baru 
    bool condition = false;
    for(int i = 0; i < total - 1; i++) { 
        for(int j = i + 1; j < total; j++) {
            if(attr == 1) {
                condition = type == 1 ? caterings[i].tujuan > caterings[j].tujuan : caterings[i].tujuan < caterings[j].tujuan;
            } else if (attr == 2) {
                condition = type == 1 ? caterings[i].bungkusan > caterings[j].bungkusan : caterings[i].bungkusan < caterings[j].bungkusan;
            }
            if(condition) {
                Catering swapped_catering = caterings[j];
                caterings[j] = caterings[i];
                caterings[i] = swapped_catering;
            }
        }
    }
    //menampilkan data pada file data.txt
    for(int i = 0; i < total; i++) { 
        cout << "data ke - " << i + 1 << endl;
        cout << "Nama  : " << caterings[i].tujuan << endl;
        cout << "Stok  : " << caterings[i].bungkusan << endl;
    }


}

void searching(){
        //deklarasi vaiabel searching atribut
        string katakunci;
        
        cout << "\n   ---------------------------------------------";
        cout << "\n   |       >> Program Pengurutan Data <<       |";
        cout << "\n   ---------------------------------------------\n";
        cout << "Masukkan kata yang ingin dicari: "; cin >> katakunci;

        Catering catering;
        bool ditemukan = false;
        string tmp, bungkusan, tujuan;

        myfile.open("data.txt", ios::in);
        while (getline(myfile, tmp) && !ditemukan) {
            
            stringstream line(tmp);
            getline(line, tujuan, ',');
            getline(line, bungkusan, '\n');
            if(tujuan.find(katakunci) != std::string::npos || bungkusan.find(katakunci) != std::string::npos) {
                ditemukan = true;
                catering.bungkusan = stoi(bungkusan);
                catering.tujuan = tujuan;
            }
        }
        myfile.close();
        if(ditemukan) {
            cout << "Data ditemukan!" << endl;
            cout << "Nama  : " << catering.tujuan << endl;
            cout << "Stok  : " << catering.bungkusan << endl;
        } else {
            cout << "Data tidak ditemukan!" << endl;
        }
}
// tampilan pembuat
void pembuat(){
    cout<<"________________________________________________"<<endl;
    cout<<"=                  Dibuat Oleh                 ="<<endl;
    cout<<"________________________________________________"<<endl;
    cout<<"\nNama \t\t: Ananta yusra Putra Akmal"<<endl;
    cout<<"NIM \t\t: 2109106024"<<endl;
    cout<<"Kelas \t\t: Informatika A 2021"<<endl;
    cout<<"Praktikum \t: APL Posttest 7"<<endl;
    cout<<"________________________________________________\n\n"<<endl;
}

int main() {
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
    cout<< "===================================================" << endl
        << "                     MENU UTAMA                    " << endl
        << "===================================================" << endl
        << "1. Tambah Data" << endl
        << "2. Tampilkan Seluruh Data" << endl
        << "3. Update Data" << endl
        << "4. Hapus Data" << endl
        << "5. Sorting" << endl
        << "6. Searching" << endl
        << "7. Exit" << endl
        << endl;

    cout << "Pilih Menu [1-8]: ";
    cin >> x;

    // pilihan 1 sebagai input data 
    if (x == "1"){
        inputData();
        goto menu;
    }
    // pilihan 2 sebagai melihat/menampilkan data 
    else if ( x=="2"){
        readData();
        goto menu;
    }
    // // pilihan 3 sebagai update data 
    else if (x == "3"){
        updateData();
        goto menu;
    }
    // // pilihan 4 sebagai hapus data 
    else if (x== "4") {
        deleteData();
        cout << "Penghapusan Data Sukses" << endl;
        goto menu;
    }
    // pilihan 5 sebagai sorting
    else if (x== "5") {
            system("cls");
            sorting();
            cout << "\nPengurutan Selesai" << endl;
        goto menu;
    }
    // pilihan 7 sebagai searching
    else if (x== "6") {
            system("cls");
            searching();
            cout << "\nPencarian Selesai\n" << endl;
        goto menu;
    }
    // pilihan 8 sebagai exit program
    else if (x == "7") {
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



