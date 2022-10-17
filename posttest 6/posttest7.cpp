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
    int attr, type;
    Catering caterings[1000];
    cout << "\n   ---------------------------------------------";
    cout << "\n   |       >> Program Pengurutan Data <<       |";
    cout << "\n   ---------------------------------------------\n";
    

    cout<<"\t\t SORTING ATRIBUT\n";
    cout<<"1. Tujuan "<<endl;
    cout<<"2. Bungkusan "<<endl;
    cout<<"Masukkan Pilihan : "; cin>>attr;

    cout<<"\t\t TIPE SORTING\n";
    cout<<"1. Asc "<<endl;
    cout<<"2. Desc "<<endl;
    cout<<"Masukkan Pilihan : "; cin>>type;

    myfile.open("data.txt", ios::in);
    string tmp, bungkusan;
    int index = 0;
    Catering catering;
    while (getline(myfile, tmp)) {
        
        stringstream line(tmp);
        getline(line, catering.tujuan, ',');
        getline(line, bungkusan, '\n');

        catering.bungkusan = stoi(bungkusan);
        caterings[index] = catering;
        index++;
    }
    myfile.close();

    int total = getTotal();
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


}

// void searching(){
//         //deklarasi vaiabel searching atribut
//         int pilihan1;
//         //input memilih searching atribut
//         cout<<"\t\t SORTING ATRIBUT\n";
//         cout<<"1. Bungkusan "<<endl;
//         cout<<"2. Tujuan "<<endl;
//         cout<<"Masukkan Pilihan : "; cin>>pilihan1;
//         cout<<"'"<<endl;
//         //piihan 1 searching atribut bungkusan (integer)
//         if (pilihan1 == 1){
//             cout << "===================================================" << endl;
//             cout << "            Searching Berdasarkan Bungkusan        " << endl;
//             cout << "===================================================" << endl;
//             // deklarasi variabel 
//             // k = data yang ingin di cari di data bungkusan
//             // i = nilai di dalam proses searching
//             int i, k;
//             bool found;
//             cout<<"\nMasukan Jumlah Bungkusan yang dicari = ";
//             cin >>k;
//             // proses searching
//             found =false;
//             i=0;
//             while ((i<10)&(!found))
//             {
//                 if (caterings[i].bungkusan==k)
//                 found=true;
//                 else
//                 i=i+1;
//             }
//             if(found){
//             //output dari searching 
//             cout<<"\n"<<endl;
//             cout<<"\t\tDATA DI TEMUKAN"<<endl;
//             cout<<"Bungkusan : "<<caterings[i].bungkusan <<endl;
//             cout<<"Tujuan    : "<<caterings[i].tujuan <<endl;
//             }
//             else
//             cout<<"\nBungkusan "<<k<<" tidak ada dalam data\n";
//             }	
//         //piihan 2 searching atribut tujuan (string)
//         if (pilihan1 == 2){
//             cout << "===================================================" << endl;
//             cout << "             Searching Berdasarkan Tujuan          " << endl;
//             cout << "===================================================" << endl;
//             // deklarasi variabel 
//             // k = data yang ingin di cari di data bungkusan
//             // i = nilai di dalam proses searching
//             int i; 
//             string k;
//             bool found;
//             cout<<"\nMasukan Tujuan yang di cari = ";
//             cin >>k;
//             // proses searching
//             found =false;
//             i=0;
//             while ((i<10)&(!found))
//             {
//                 if (caterings[i].tujuan==k)
//                 found=true;
//                 else
//                 i=i+1;
//             }
//             if(found){
//             //output dari searching 
//             cout<<"\n"<<endl;
//             cout<<"\t\tDATA DI TEMUKAN"<<endl;
//             cout<<"Bungkusan : "<<caterings[i].bungkusan <<endl;
//             cout<<"Tujuan    : "<<caterings[i].tujuan <<endl;
//             }
//             else
//             cout<<"\nTujuan "<< k <<" tidak ada dalam data\n";
//             }	
// }
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
        << "7. REFRESH" << endl
        << "8. Exit" << endl
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
    // else if (x== "7") {
    //         system("cls");
    //         searching();
    //         cout << "\nPencarian Selesai\n" << endl;
    //     goto menu;
    // }
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



