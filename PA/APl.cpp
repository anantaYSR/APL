#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <sstream>
using namespace std;

struct tujuan{
	string negara;
	string kota;
	string kecamatan;
	string alamat;
};

struct date {
	string hari;
	int tanggal;
	int bulan;
	int tahun;	
};

struct kurir{
    string username;
    string password;
    string nama;
    long long int nomorhp;
    string id_kurir;
    };
    

struct data_paket{
	string id;
	string nama_penerima;
	long long int nomor_penerima;
	tujuan des_paket;
	date date_masuk;
	string zona;
	string nama_kurir;
	long long int nomor_kurir;
	date keluar_paket;
	string id_kurir;
}; 
fstream file;

struct login{
	kurir login;
};

login kurirlogin;

void akun_kurir(void);
void menu_manajemen_admin(void);
void menu_login_kurir(void);
void menu_kurir(void);

const int MAX = 36;

string printRandomString(int n)
{
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						'h', 'i', 'j', 'k', 'l', 'm', 'n',
						'o', 'p', 'q', 'r', 's', 't', 'u',
						'v', 'w', 'x', 'y', 'z' ,'1', '2',
						'3', '4', '5', '6', '7', '8', '9', '0'};

	string res = "";
	for (int i = 0; i < n; i++)
		res = res + alphabet[rand() % MAX]; 
	
	return res;
}


void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);

}

void kelompok(){
const char rocket[] =
"          _\n\
         /^\\\n\
         |-|\n\
         | |\n\
         |E|\n\
         |N|\n\
         |A|\n\
         |M|\n\
         | |\n\
        /| |\\\n\
       / | | \\\n\
      |  | |  |\n\
       `-\"\"\"-`\n\
";
	{
    for (int i = 0; i < 35; i++) cout << endl; // melompat ke bawah konsol
    cout << rocket ;
    int j = 200000;
    for (int i = 0; i < 35; i++) {
        usleep(j); // bergerak lebih cepat,
        j = (int)(j * 0.8); // waktu sleep
        cout << endl; // memindahkan baris roket ke atas
    }
}
}


bool eror(int milih){
	while(true){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}
		else{
			break;
			return true;
		}
    }
	return 0;
}

vector<data_paket> daftarPaket() {
	file.open("data_paket.txt", ios::in);
	vector<data_paket> daftar;
	data_paket paket;
	string nomor_penerima, nomor_kurir;
	string keluar_paket_hari, keluar_paket_tanggal, keluar_paket_bulan, keluar_paket_tahun;
	string masuk_paket_hari, masuk_paket_tanggal, masuk_paket_bulan, masuk_paket_tahun = "0";
	date keluar_paket, date_masuk;
	string line;

	if(file.is_open()) {
		while(getline(file, line)) {
			stringstream str(line);
			getline(str, paket.id, ';');
			getline(str, paket.nama_penerima, ';');
			getline(str, nomor_penerima, ';');

			getline(str, paket.des_paket.negara, ';');
			getline(str, paket.des_paket.kota, ';');
			getline(str, paket.des_paket.kecamatan, ';');
			getline(str, paket.zona, ';');
			getline(str, paket.des_paket.alamat, ';');

			getline(str, masuk_paket_hari, ',');
			getline(str, masuk_paket_tanggal, ',');
			getline(str, masuk_paket_bulan, ',');
			getline(str, masuk_paket_tahun, '.');

			getline(str, paket.id_kurir, ';');
			getline(str, paket.nama_kurir, ';');
			getline(str, nomor_kurir, ';');

			getline(str, keluar_paket_hari, ',');
			getline(str, keluar_paket_tanggal, ',');
			getline(str, keluar_paket_bulan, ',');
			getline(str, keluar_paket_tahun, '\n');

			paket.nomor_penerima = stoll(nomor_penerima);
			paket.nomor_kurir = stoll(nomor_kurir);

			paket.date_masuk.hari = masuk_paket_hari;
			paket.date_masuk.tanggal = stoi(masuk_paket_tanggal);
			paket.date_masuk.bulan = stoi(masuk_paket_bulan);
			paket.date_masuk.tahun = stoi(masuk_paket_tahun);

			paket.keluar_paket.hari = keluar_paket_hari;
			paket.keluar_paket.tanggal = stoi(keluar_paket_tanggal);
			paket.keluar_paket.bulan = stoi(keluar_paket_bulan);
			paket.keluar_paket.tahun = stoi(keluar_paket_tahun);
			daftar.push_back(paket);
		}
	} else {
		cout << "File tidak ada!";
	}
	file.close();
	return daftar;
}

vector<data_paket> penerima_paket=daftarPaket();
vector<data_paket> paketan= penerima_paket;

vector<kurir> daftarKurir(){
	file.open("data_kurir.txt", ios::in);
	vector<kurir> daftar;
	kurir kurir;
	string nomor_kurir;
	string line;

	if(file.is_open()) {
		while(getline(file, line)) {
			stringstream str(line);
			getline(str, kurir.id_kurir, ';');
			getline(str, kurir.nama, ';');
			getline(str, nomor_kurir, ';');
			getline(str, kurir.username, ';');
			getline(str, kurir.password, '\n');

			kurir.nomorhp = stoll(nomor_kurir);
			daftar.push_back(kurir);
		}
	} else {
		cout << "File tidak ada!";
	}
	file.close();
	return daftar;
}

vector<kurir>data_kurir=daftarKurir();



string lowercase(string huruf){
    for(int x = 0;x < huruf.length();x++){
        huruf[x] = tolower(huruf[x]);
    }
    return huruf;
}

void write_file_paket(){
	file.open("data_paket.txt", ios::out);
    if(file.is_open()){
        for(int i=0;i < penerima_paket.size();i++){
			if (penerima_paket[i].keluar_paket.bulan!=0){
				file  << penerima_paket[i].id << ";";
				file << penerima_paket[i].nama_penerima<< ";";
				file << penerima_paket[i].nomor_penerima<< ";";
				penerima_paket[i].des_paket.negara = "Indonesia";
				file << penerima_paket[i].des_paket.negara<< ";";
				penerima_paket[i].des_paket.kota= "Samarinda";
				file << penerima_paket[i].des_paket.kota<< ";";
				file << penerima_paket[i].des_paket.kecamatan<< ";";
				file << penerima_paket[i].zona<< ";";
				file << penerima_paket[i].des_paket.alamat<< ";";
				file << penerima_paket[i].date_masuk.hari <<","<<penerima_paket[i].date_masuk.tanggal<<","<<penerima_paket[i].date_masuk.bulan<<","<<penerima_paket[i].date_masuk.tahun << ".";
				file << penerima_paket[i].id_kurir << ";";
				file << penerima_paket[i].nama_kurir << ";";
				file << penerima_paket[i].nomor_kurir << ";";
				file << penerima_paket[i].keluar_paket.hari<<","<<penerima_paket[i].keluar_paket.tanggal<<","<<penerima_paket[i].keluar_paket.bulan<<","<<penerima_paket[i].keluar_paket.tahun<< "\n";
			}
		}
    }file.close();
}

void open_file_paket(){
	file.open("data_paket.txt", ios::in);
	if(!file.is_open()){
		file.open("data_paket.txt", ios::out | ios::trunc);
		file.close();
	}
	file.close();
}

void append_file_paket(vector<data_paket> &penerima_paket){
	file.open("data_paket.txt",ios::app);
    if(file.is_open()){
		file  << penerima_paket[penerima_paket.size()-1].id << ";";
		file << penerima_paket[penerima_paket.size()-1].nama_penerima<< ";";
		file << penerima_paket[penerima_paket.size()-1].nomor_penerima<< ";";
		penerima_paket[penerima_paket.size()-1].des_paket.negara = "Indonesia";
		file << penerima_paket[penerima_paket.size()-1].des_paket.negara<< ";";
		penerima_paket[penerima_paket.size()-1].des_paket.kota= "Samarinda";
		file << penerima_paket[penerima_paket.size()-1].des_paket.kota<< ";";
		file << penerima_paket[penerima_paket.size()-1].des_paket.kecamatan<< ";";
		file << penerima_paket[penerima_paket.size()-1].zona<< ";";
		file << penerima_paket[penerima_paket.size()-1].des_paket.alamat<< ";";
		file << penerima_paket[penerima_paket.size()-1].date_masuk.hari <<","<<penerima_paket[penerima_paket.size()-1].date_masuk.tanggal<<","<<penerima_paket[penerima_paket.size()-1].date_masuk.bulan<<","<<penerima_paket[penerima_paket.size()-1].date_masuk.tahun << ".";
		file << penerima_paket[penerima_paket.size()-1].id_kurir << ";";
		file << penerima_paket[penerima_paket.size()-1].nama_kurir << ";";
		file << penerima_paket[penerima_paket.size()-1].nomor_kurir << ";";
		file << penerima_paket[penerima_paket.size()-1].keluar_paket.hari<<","<<penerima_paket[penerima_paket.size()-1].keluar_paket.tanggal<<","<<penerima_paket[penerima_paket.size()-1].keluar_paket.bulan<<","<<penerima_paket[penerima_paket.size()-1].keluar_paket.tahun<< "\n";
    }file.close();
}

void file_open_kurir(){
	file.open("data_kurir.txt", ios::in);
	if(!file.is_open()){
		file.open("data_kurir.txt", ios::out | ios::trunc);
		file.close();
	}
	file.close();
}


void write_file_kurir(){
	file.open("data_kurir.txt", ios::out);
    if(file.is_open()){
        for(int i=0;i < data_kurir.size();i++){
			file  << data_kurir[i].id_kurir << ";";
			file << data_kurir[i].nama<< ";";
			file << data_kurir[i].nomorhp<< ";";
			file << data_kurir[i].username<< ";";
			file << data_kurir[i].password<< "\n";
		}
    }file.close();
}

void append_file_kurir(vector<kurir> &data_kurir){
	file.open("data_kurir.txt",ios::app);
    if(file.is_open()){
		file  << data_kurir[data_kurir.size()-1].id_kurir << ";";
		file << data_kurir[data_kurir.size()-1].nama<< ";";
		file << data_kurir[data_kurir.size()-1].nomorhp<< ";";
		file << data_kurir[data_kurir.size()-1].username<< ";";
		file << data_kurir[data_kurir.size()-1].password<< "\n";
    }file.close();
}

void inputan_user(int i){
	int pilih;
	setcolor(7);
	cout << "====================DATA PENERIMA PAKET=====================\n";
	cout << "\nNama 			: "; fflush(stdin); getline(cin, penerima_paket[i].nama_penerima);
	cout << "\nNomor Hp/WhatsApp 	: "; cin >> penerima_paket[i].nomor_penerima;
	cout << "============================================================\n";
	cout << "                          ALAMAT PENERIMA                   \n";
	cout << endl;
	cout <<  "===========================================================" << endl
			<< 	 "                      Daftar Kecamatan                     " << endl
			<<   "===========================================================" << endl
			<<   "[1] Palaran  		" << endl
			<<   "[2] Sambutan 		" << endl
			<<   "[3] Loa Janan ILir		" << endl
			<<   "[4] Samarinda Kota 		" << endl
			<<   "[5] Samarinda Utara 	" << endl
			<<   "[6] Sungai Pinang 	" << endl
			<<   "[7] Samarinda Ilir	" << endl
			<<   "[8] Samarinda Ulu	" << endl
			<<   "[9] Samarinda Seberang 	" << endl
			<<   "[10] Sungai Kunjang 	" << endl; 
	do{
		setcolor(7);
		cout << "\nMasukkan Pilihan	: "; cin >> pilih;
	} while(eror(pilih)==true);

	switch (pilih){
		case 1:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Palaran";
			penerima_paket[i].zona = "Zona 1";
			break;
		case 2:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Sambutan";
			penerima_paket[i].zona = "Zona 1";
			break;
		case 3:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Loa Janan Ilir";
			penerima_paket[i].zona = "Zona 1";
			break;
		case 4:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Samarinda Kota";
			penerima_paket[i].zona = "Zona 2";
			break;
		case 5:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Samarinda Utara";
			penerima_paket[i].zona = "Zona 2";
			break;
		case 6:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Sungai Pinang";
			penerima_paket[i].zona = "Zona 2";
			break;
		case 7:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Samarinda Ilir";
			penerima_paket[i].zona = "Zona 2";
			break;
		case 8:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Samarinda Ulu";
			penerima_paket[i].zona = "Zona 3";
			break;
		case 9:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Samarinda Seberang";
			penerima_paket[i].zona = "Zona 3";
			break;
		case 10:
			setcolor(7);
			penerima_paket[i].des_paket.kecamatan= "Sungai Kunjang";
			penerima_paket[i].zona = "Zona 3";
			break;
	}
	setcolor(7);
	cout << "\nAlamat lengkap 		: "; fflush(stdin); getline(cin, penerima_paket[i].des_paket.alamat);
	cout << "===========================================================\n";
	cout << "                    TANGGAL MASUK PAKET                    \n";
	cout << "Hari 					: " ;cin >> penerima_paket[i].date_masuk.hari;
	cout << "\nTanggal 				: " ;cin >> penerima_paket[i].date_masuk.tanggal;
	cout << "\nBulan 				: " ;cin >> penerima_paket[i].date_masuk.bulan;
	cout << "\nTahun 				: " ;cin >> penerima_paket[i].date_masuk.tahun;
}

void tambah_paket(vector<data_paket> &penerima_paket){
	system("cls");
	setcolor(7);
	srand(time(NULL));
	int n = 10;
	data_paket penerima;
	int pilih;
	penerima.id = printRandomString(n);
	cout << "====================DATA PENERIMA PAKET=====================\n";
	cout << "\nNama 			: "; fflush(stdin); getline(cin, penerima.nama_penerima);
	cout << "\nNomor Hp/WhatsApp 	: "; cin >> penerima.nomor_penerima;
	cout << "============================================================\n";
	cout << "                          ALAMAT PENERIMA                   \n";
	cout << endl;
	cout <<  "===========================================================" << endl
			<< 	 "                      Daftar Kecamatan                     " << endl
			<<   "===========================================================" << endl
			<<   "[1] Palaran  		" << endl
			<<   "[2] Sambutan 		" << endl
			<<   "[3] Loa Janan ILir		" << endl
			<<   "[4] Samarinda Kota 		" << endl
			<<   "[5] Samarinda Utara 	" << endl
			<<   "[6] Sungai Pinang 	" << endl
			<<   "[7] Samarinda Ilir	" << endl
			<<   "[8] Samarinda Ulu	" << endl
			<<   "[9] Samarinda Seberang 	" << endl
			<<   "[10] Sungai Kunjang 	" << endl; 
	do{
		setcolor(7);
		cout << "\nMasukkan Pilihan	: "; cin >> pilih;
	} while(eror(pilih)==true);
	
	switch (pilih){
		case 1:
			setcolor(7);
			penerima.des_paket.kecamatan= "Palaran";
			penerima.zona = "Zona 1";
			break;
		case 2:
			setcolor(7);
			penerima.des_paket.kecamatan= "Sambutan";
			penerima.zona = "Zona 1";
			break;
		case 3:
			setcolor(7);
			penerima.des_paket.kecamatan= "Loa Janan Ilir";
			penerima.zona = "Zona 1";
			break;
		case 4:
			setcolor(7);
			penerima.des_paket.kecamatan= "Samarinda Kota";
			penerima.zona = "Zona 2";
			break;
		case 5:
			setcolor(7);
			penerima.des_paket.kecamatan= "Samarinda Utara";
			penerima.zona = "Zona 2";
			break;
		case 6:
			setcolor(7);
			penerima.des_paket.kecamatan= "Sungai Pinang";
			penerima.zona = "Zona 2";
			break;
		case 7:
			setcolor(7);
			penerima.des_paket.kecamatan= "Samarinda Ilir";
			penerima.zona = "Zona 2";
			break;
		case 8:
			setcolor(7);
			penerima.des_paket.kecamatan= "Samarinda Ulu";
			penerima.zona = "Zona 3";
			break;
		case 9:
			setcolor(7);
			penerima.des_paket.kecamatan= "Samarinda Seberang";
			penerima.zona = "Zona 3";
			break;
		case 10:
			setcolor(7);
			penerima.des_paket.kecamatan= "Sungai Kunjang";
			penerima.zona = "Zona 3";
			break;
	}
	setcolor(7);
	cout << "\nAlamat lengkap 		: "; fflush(stdin); getline(cin, penerima.des_paket.alamat);
	cout << "===========================================================\n";
	cout << "                    TANGGAL MASUK PAKET                    \n";
	cout << "Hari 			: " ;cin >> penerima.date_masuk.hari;
	cout << "\nTanggal 		: " ;cin >> penerima.date_masuk.tanggal;
	cout << "\nBulan 		: " ;cin >> penerima.date_masuk.bulan;
	cout << "\nTahun 		: " ;cin >> penerima.date_masuk.tahun;
	penerima.nomor_kurir=0;
	penerima.keluar_paket.tanggal=0;
	penerima.keluar_paket.bulan=0;
	penerima.keluar_paket.tahun=0;
	penerima_paket.push_back(penerima);
	paketan=penerima_paket;
	append_file_paket(penerima_paket);
	
}

void print_out(int i, vector<data_paket> &penerima_paket){
	setcolor(4);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	setcolor(2);
	cout << "                      DATA PENGIRIM                        \n\n";
	setcolor(7);
	cout << "Nomor Resi 		: " << penerima_paket[i].id << endl;
	cout << "Nama 			: " << penerima_paket[i].nama_penerima<< endl;
	cout << "Nomor HP 		: " << penerima_paket[i].nomor_penerima<< endl;
	cout << "==========================================================\n";
	setcolor(2);
	cout << "                      ALAMAT PENERIMA                     \n\n";
	setcolor(7);
	penerima_paket[i].des_paket.negara = "Indonesia";
	cout << "Negara			: " << penerima_paket[i].des_paket.negara<< endl;
	penerima_paket[i].des_paket.kota= "Samarinda";
	cout << "Kota			: " << penerima_paket[i].des_paket.kota<< endl;
	cout << "Kecamatan		: " << penerima_paket[i].des_paket.kecamatan<< endl;
	cout << "Wilayah zona		: " << penerima_paket[i].zona<< endl;
	cout << "Alamat lengkap		: " << penerima_paket[i].des_paket.alamat<< endl;
	cout << "Paket masuk		: " << penerima_paket[i].date_masuk.hari <<", "<<penerima_paket[i].date_masuk.tanggal<<"-"<<penerima_paket[i].date_masuk.bulan<<"-"<<penerima_paket[i].date_masuk.tahun << endl;
	cout << "==========================================================\n";
	setcolor(2);
	cout << "                        DATA KURIR                        \n\n";
	setcolor(7);
	cout << "ID Kurir		: " << penerima_paket[i].id_kurir << endl;
	cout << "Nama Kurir		: " << penerima_paket[i].nama_kurir << endl;
	cout << "Nomor HP Kurir		: " << penerima_paket[i].nomor_kurir << endl;
	cout << "Tanggal dikirim		: " << penerima_paket[i].keluar_paket.hari<<", "<<penerima_paket[i].keluar_paket.tanggal<<"-"<<penerima_paket[i].keluar_paket.bulan<<"-"<<penerima_paket[i].keluar_paket.tahun<< endl;
	setcolor(4);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
}

void selectionSort(vector<data_paket> &paketan)
{
	system("cls");
	setcolor(7);
	int pilih;
	cout <<  "======================" << endl
		<< 	 "   	PENGURUTAN 		" << endl
		<<   "======================" << endl
		<<   "[1] Ascending 		" << endl
		<<   "[2] Descending		" << endl;
	setcolor(2);
	cout << "\nMasukkan pilihan: "; cin >> pilih;
	setcolor(7);
	system("cls");
	int i, j, min_idx;
	for (i = 0; i < paketan.size()-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < paketan.size(); j++)
		{
			switch (pilih){
				case 1:
					if (paketan[j].zona < paketan[min_idx].zona)
					{
						min_idx = j;	
					}
					break;
				case 2:
					if (paketan[j].zona > paketan[min_idx].zona)
					{
						min_idx = j;	
					}
					break;
				default:
					selectionSort(paketan);
			}
		}
		data_paket temp = paketan[i];
		paketan[i] = paketan[min_idx];
		paketan[min_idx] = temp;
	}
}

void bubble(vector<data_paket> &paketan){
	data_paket swap;
	string tahun_masuk;
	system("cls");
	stringstream tahun;
	setcolor(7);
	int pilih;
	cout <<  "======================" << endl
		<< 	 "   	PENGURUTAN 		" << endl
		<<   "======================" << endl
		<<   "[1] Ascending 		" << endl
		<<   "[2] Descending		" << endl;
	setcolor(2);
	cout << "\nMasukkan pilihan: "; cin >> pilih;
	system("cls");
	setcolor(7);
	switch (pilih){
		case 1:
			for (int i=0; i<paketan.size()-1; i++){
				for(int j=0; j<paketan.size()-1; j++){
					if (paketan[j].nama_penerima > paketan[j+1].nama_penerima){
						swap = paketan[j];
						paketan[j] = paketan[j+1];
						paketan[j+1] = swap;
					}
				}	
			}
			break;	
		case 2:
			for(int i=0; i<paketan.size()-1; i++){
				for(int j=0; j<paketan.size()-1; j++){
					if  (paketan[j].nama_penerima < paketan[j+1].nama_penerima){
						swap = paketan[j];
						paketan[j] = paketan[j+1];
						paketan[j+1] = swap;
					}
				}	
			}
			break;
		default:
			bubble(paketan);
		break;
	}
}

void sort(){
	system("cls");
	int pilih;
	setcolor(7);
	cout << "=============================	" << endl
		<< 	 "    Sort Data Berdasarkan		" << endl
		<<   "=============================	" << endl
		<<   "[1] Zona						" << endl
		<<   "[2] Nama Penerima				" << endl;
	cout << endl;
	do{
		setcolor(2);
		cout << "\nMasukkan Pilihan: "; cin >> pilih;
	} while(eror(pilih)==true);
	if (pilih==1){
		selectionSort(paketan);
	}
	else if(pilih==2){
		bubble(paketan);
	}
	else{
		cout << "Tidak ada pilihan"; getch();
		sort();
	}
	
}           


void tampilan_paket(){
	system("cls");
	if (paketan.size()==0){
		setcolor(4);
		cout << "Tidak ada paket yang masuk\n"; getch();
	}
	else {
		sort();
		for(int i = 0; i < paketan.size(); i++){
			print_out(i, paketan);
		}
		getch();
	}
	
}

void ubah_datapaket(){
	system("cls");
	string id;
	if (penerima_paket.size() == 0){
		setcolor(4);
		cout << "Tidak ada data paket yang masuk!!!\n"; getch();
	}
	else {
		tampilan_paket();
		setcolor(2);
		cout << "\nMasukkan nomor resi paket yang ingin diubah: "; cin >> id; cout << endl;
		for(int i = 0; i < penerima_paket.size(); i++){
			if (penerima_paket[i].id == id){
				system("cls");
				inputan_user(i);
			}
		}
	}
	paketan=penerima_paket;
}


void hapus_paket(){
	system("cls");
	string id;
	char pilih;
	if (penerima_paket.size() == 0){
		setcolor(4);
		cout << "Tidak ada  paket yang bisa dihapus\n"; getch();
	}
	else {
		tampilan_paket();
		setcolor(2);
		cout << "\nMasukkan nomor resi paket yang ingin dihapus: "; cin >> id; cout << endl;
		for(int i = 0; i < penerima_paket.size(); i++){
			if (penerima_paket[i].id == id){
				system("cls");
				print_out(i, penerima_paket);
				setcolor(2);
				cout << "\nApakah ingin menghapus ? (y/t) "; cin >> pilih;
						switch (pilih){
							case 'y':
								penerima_paket.erase(penerima_paket.begin() + i);
								setcolor(4);
								cout << "\nBerhasil terhapus "; getch();
								break;
							default:
								setcolor(4);
								cout << "Tidak terhapus"; getch();
						} 
			}
		}
	}
	paketan=penerima_paket;	
}
	
int binarisearch(int pilih)
{
	system("cls");
	bool point;
    string num;
	int beg = 0;
	setcolor(7);
	int end=penerima_paket.size()-1;
	int index= -1;
	cout<<"Data yang dicari	: ";
	cin>>num;
	string cari=lowercase(num);
	string data_dicari;
	switch (pilih){
		case 1:
			for (int i=0; i<penerima_paket.size()-1; i++){
				for(int j=0; j<penerima_paket.size()-1; j++){
					if(penerima_paket[j].id>penerima_paket[j+1].id){
						data_paket swap = penerima_paket[j];
						penerima_paket[j] = penerima_paket[j+1];
						penerima_paket[j+1] = swap;
					}
				}	
			}
			while(beg<=end){
				int mid=(end+beg)/2;
				data_dicari=lowercase(penerima_paket[mid].id);
				if(data_dicari.find(cari)!=string::npos){
					index= mid +1;
					for (int i=0; i<penerima_paket.size(); i++){
						data_dicari=lowercase(penerima_paket[i].id);
						if (data_dicari.find(cari)!=string::npos){
							print_out(i, penerima_paket);
						}
						getch();
					}
					break;
				}
				else{
					if(cari>data_dicari){
						beg= mid+1;
					}
					else{
						end=mid-1;
					}
				}
			}
			break;
		case 2:
			for (int i=0; i<penerima_paket.size()-1; i++){
				for(int j=0; j<penerima_paket.size()-1; j++){
					if(penerima_paket[j].nama_penerima>penerima_paket[j+1].nama_penerima){
						data_paket swap = penerima_paket[j];
						penerima_paket[j] = penerima_paket[j+1];
						penerima_paket[j+1] = swap;
					}
				}	
			}
			while(beg<=end){
				int mid=(end+beg)/2;
				data_dicari=lowercase(penerima_paket[mid].nama_penerima);
				if(data_dicari.find(cari)!=string::npos){
					index= mid +1;
					for (int i=0; i<penerima_paket.size(); i++){
						data_dicari=lowercase(penerima_paket[i].nama_penerima);
						if (data_dicari.find(cari)!=string::npos){
							print_out(i, penerima_paket);
						}
						getch();
					}
					break;
				}
				else{
					if(cari>data_dicari){
						beg= mid+1;
					}
					else{
						end=mid-1;
					}
				}
			}
			break;
	}

	if (index==-1){
		setcolor(4);
		cout << "\nData tidak ditemukan"; getch();
	}
	return 0;
}

void search(){
	system("cls");
	int pilih;
	setcolor(7);
	cout << "=============================	" << endl
		<< 	 "    Data yang dicari				" << endl
		<<   "=============================		" << endl
		<<   "[1] Nomor Resi					" << endl
		<<   "[2] Nama Penerima					" << endl;
	cout << endl;
	do{
		setcolor(2);
		cout << "\nMasukkan Pilihan: "; cin >> pilih;
	} while(eror(pilih)==true);
	switch (pilih)
	{
	case 1:
		binarisearch(1);
		break;
	case 2:
		binarisearch(2);
		break;
	default:
		setcolor(4);
		cout << "\nMasukkan pilihan sesuai menu"; getch();
		search();
	}
}

// prosedur untuk keluar program
void keluar_program(){
	system("cls");
	setcolor(10);
	cout<<"\n\n\t\t\t------------------------------------------------------"<< endl;
	setcolor(5);
	cout<<"\t\t\t=            Anda telah keluar dari program          ="<< endl;
	setcolor(10);
	cout<<"\t\t\t------------------------------------------------------"<< endl;
	getch();
	exit(0);
}


//=======================================================================

void tambah_akun_kurir(vector<kurir> &data_kurir){
    system("cls");
	srand(time(NULL));
	kurir kuriran;
	setcolor(2);
	cout << "========================================================" << endl;
	cout <<	"                        Buat Akun Kurir                 " << endl;
	cout << "========================================================\n" << endl;
	setcolor(7);
    kuriran.id_kurir=printRandomString(10);
    cout << "Masukan username akun\t\t: ";
    fflush(stdin);getline(cin,kuriran.username);
    cout << endl;
    cout << "Masukan pasword akun\t\t: ";
    fflush(stdin);getline(cin,kuriran.password);
    cout << endl;
    cout << "Masukan nama lengkap\t\t: ";
    fflush(stdin);getline(cin,kuriran.nama);
    cout << endl;
    cout << "Masukan nomor HP/WhatsApp\t: "; cin >> kuriran.nomorhp;
    data_kurir.push_back(kuriran);
	setcolor(2);
    cout << "\n\n-----------------------------------------"<<endl;
    cout << "|     telah berhasil menambahkan akun   |"<<endl;
    cout << "-----------------------------------------"<<endl; getch();
	append_file_kurir(data_kurir);
}

void daftar_akun_kurir(vector<kurir> &data_kurir){
    int nomor=0;
    system("cls");
	setcolor(5);
    cout << "======================================================================================================" << endl;
	setcolor(7);
    cout << "|\tno\t" "|\t\ttugas\t\t" "|\t password \t|\t\tID\t\t"<<endl;
	setcolor(5);
    cout << "======================================================================================================" << endl;
    //perulangan untuk menampilkan seluruh data yang telah di daftarkan
    for(int i=0;i<data_kurir.size();i++)
    {   setcolor(7);
		nomor++;
        cout << "|\t"<<nomor<<"\t|";
        cout << "\t" << data_kurir[i].username << "\t\t";
        cout <<"\t|\t"<<data_kurir[i].password << "\t";
        cout <<"\t|\t"<<data_kurir[i].id_kurir;
        cout <<endl;
		setcolor(5);
        cout << "======================================================================================================\n";

    }
    getch();
}

void hapus_akun_kurir(){
	system("cls");
	setcolor(7);
	string id;
	char pilih;
	cout << "ID		: " << kurirlogin.login.id_kurir << endl
		<<	 "Nama		: " << kurirlogin.login.nama << endl
		<<	 "Nomor HP	: " << kurirlogin.login.nomorhp << endl;
	setcolor(2);
	cout <<"==============================="<<endl;
	setcolor(7);
	cout << "\nMasukan ID akun : "; cin >> id ; cout << endl;
	for(int i = 0; i < data_kurir.size(); i++){
		if (data_kurir[i].id_kurir == id){
			setcolor(7);
			cout << "\nApakah ingin menghapus akun ? (y/t) "; cin >> pilih;
					switch (pilih){
						case 'y':
							data_kurir.erase(data_kurir.begin() + i);
							setcolor(4);
							cout << "\nBerhasil terhapus "; getch();
							break;
						default:
							setcolor(4);
							cout << "Tidak terhapus "; getch();
					} 
		}
	}
	write_file_kurir();
}

void ubah_akun_kurir(){
	system("cls");
	setcolor(7);
	string id;
	cout << "ID		: " << kurirlogin.login.id_kurir << endl
		<<	 "Nama		: " << kurirlogin.login.nama << endl
		<<	 "Nomor HP	: " << kurirlogin.login.nomorhp << endl;
	setcolor(2);
	cout << "================================" <<endl;
	setcolor(7);
	cout << "\nMasukkan ID akun: "; cin >> id; cout << endl;
	for(int i = 0; i < data_kurir.size(); i++){
		if (data_kurir[i].id_kurir == id){
			cout << "Masukan username akun baru\t: ";
		    fflush(stdin);getline(cin,data_kurir[i].username);
		    cout << endl;
		    cout << "Masukan pasword akun baru\t: ";
		    fflush(stdin);getline(cin,data_kurir[i].password);
		    cout << endl;
		    cout << "Masukan nama lengkap\t: ";
		    fflush(stdin);getline(cin,data_kurir[i].nama);
			cout << endl;
		    cout << "Masukan nomor HP/WhatsApp\t: "; cin >> data_kurir[i].nomorhp;
		    kurirlogin= {data_kurir[i]};
		}
	}
	write_file_kurir();
}


void paketan_kurir(string zona){
	system("cls");
	setcolor(7);
	string id;
	string paket_kosong;
	for (int i=0; i<penerima_paket.size(); i++){
		if (penerima_paket[i].zona==zona && penerima_paket[i].keluar_paket.tanggal==0 ){
			print_out(i, penerima_paket);
			paket_kosong="ada";
		}
		getch();
	}
	if (paket_kosong=="ada"){
		setcolor(2);
		cout << "\nMasukkan nomor resi paket yang akan diantar :"; cin >> id;
		for (int i=0; i<penerima_paket.size(); i++){

			if (penerima_paket[i].id == id){
				setcolor(7);
				penerima_paket[i].nama_kurir=kurirlogin.login.nama;
				penerima_paket[i].nomor_kurir=kurirlogin.login.nomorhp;
				penerima_paket[i].id_kurir=kurirlogin.login.id_kurir;
				cout << "\nTANGGAL KELUAR PAKET\n";
				cout << "Hari : " ;cin >> penerima_paket[i].keluar_paket.hari;
				cout << "\nTanggal : " ;cin >> penerima_paket[i].keluar_paket.tanggal;
				cout << "\nBulan : " ;cin >> penerima_paket[i].keluar_paket.bulan;
				cout << "\nTahun : " ;cin >> penerima_paket[i].keluar_paket.tahun;	
                paketan=penerima_paket;
			}
		}
	}
	else if (paket_kosong!="ada"){
		setcolor(10);
		cout<<"\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
		setcolor(5);
		cout<<"\t\t\t=                     Tidak ada paket!!!            ="<< endl;
		setcolor(10);
		cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
		getch();
	}
}


void zona_paket(){
	system("cls");
	int pilih;
	setcolor(7);
	cout <<  "======================" << endl
		<< 	 "     ZONA   " << endl
		<<   "======================" << endl
		<<   "[1] Zona Satu	" << endl
		<<   "[2] Zona Dua	" << endl
		<<   "[3] Zona Tiga 	" << endl
		<<   "[4] Kembali 	" << endl;
	do{
		setcolor(2);
		cout << "\nMasukkan Pilihan: "; cin >> pilih;
	} while(eror(pilih)==true);
	switch(pilih){
		case 1:
			setcolor(7);
			paketan_kurir("Zona 1");
			break;
		case 2:
			setcolor(7);
			paketan_kurir("Zona 2");
			break;
		case 3:
			setcolor(7);
			paketan_kurir("Zona 3");
			break;
		case 4:
			setcolor(7);
			menu_kurir();
			break;
		default:
			setcolor(4);
			cout << "\nMasukkan pilihan sesuai menu"; getch();
			menu_kurir();
	}
}

void daftar_paket_kurir(){
system("cls");
setcolor(7);
string paketan_kurir;
for(int i = 0; i < penerima_paket.size(); i++){
	if (penerima_paket[i].id_kurir==kurirlogin.login.id_kurir){
		penerima_paket[i].nama_kurir=kurirlogin.login.nama;
		penerima_paket[i].nomor_kurir=kurirlogin.login.nomorhp;
		print_out(i, penerima_paket);
		paketan_kurir = "ada";
		
		}
		getch();	
}
if (paketan_kurir!="ada"){
	setcolor(10);
	cout<<"\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	setcolor(5);
	cout<<"\t\t\t=                Anda tidak memiliki paket!!!       ="<< endl;
	setcolor(10);
	cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	getch();
}

}

void menu_kurir(){
	system("cls");
	int milih;
	setcolor(7);
	cout <<  "ID	   : " << kurirlogin.login.id_kurir << endl
		<<	 "Nama	   : " << kurirlogin.login.nama << endl
		<<	 "Nomor HP   : " << kurirlogin.login.nomorhp << endl
		<< 	"==========================" << endl
		<< 	 "         MENU KURIR       " << endl
		<<   "==========================" << endl
		<<   "[1] Daftar Seluruh Paket	" << endl
		<<   "[2] Pilih Paket	" << endl
		<<   "[3] Daftar Paket Anda	" << endl
		<<   "[4] Ubah Akun	" << endl
		<<   "[5] Hapus Akun  		" << endl
		<<   "[6] Logout Akun	" << endl;
	do{
		setcolor(2);
		cout << "\nMasukkan Pilihan: "; cin >> milih;
	} while(eror(milih)==true);
	switch (milih){
		case 1:
			tampilan_paket();
			menu_kurir();
			break;
		case 2:
			zona_paket();
			menu_kurir();
			break;
		case 3:
			daftar_paket_kurir();
			menu_kurir();
			break;
		case 4:
			ubah_akun_kurir();
			menu_kurir();

			break;
		case 5:
			hapus_akun_kurir();
			menu_login_kurir();
			break;
		case 6:
			menu_login_kurir();
			break;
		default:
			setcolor(4);
			cout << "\nMasukkan pilihan sesuai menu"; getch();
			menu_kurir();
	}
}

void daftar_kurir(){
	system("cls");
	if (data_kurir.size()==0){
		setcolor(4);
		cout << "Tidak ada data kurir"; getch();
	}
	else{
		setcolor(2);
		cout <<   "========================================" << endl;
		cout <<   "            Biodata Semua Kurir         " << endl;
		cout <<   "========================================\n" << endl;
		for (int i=0; i<data_kurir.size(); i++){
			setcolor(7);
			cout << "\nID Kurir		: " << data_kurir[i].id_kurir << endl
				<< "Nama Kurir		: " << data_kurir[i].nama << endl
				<< "Nomor Telepon Kurir	: " << data_kurir[i].nomorhp << endl;
			cout <<   "========================================" << endl;
		} getch();
	}
}

void login_kurir(){
	system("cls");
    string pilih,pass_word,user_name;
    int milih;
    string login;
    for (int x=0;x<=3;x++){
		system("cls");
		setcolor(7);
		cout << "====================================" << endl;
		cout <<	"              Login Kurir           " << endl;
		cout << "====================================\n" << endl;
	    cout << "Masukan username : " ; fflush(stdin);getline(cin,user_name);
	    cout << endl;
	    cout << "Masukan pasword  : " ; fflush(stdin);getline(cin,pass_word);
	    for (int i=0;i<data_kurir.size();i++){
	        if (user_name == data_kurir[i].username && pass_word == data_kurir[i].password){
				setcolor(2);
				cout << "\n====================================" << endl;
				cout <<	"          Anda berhasil login         " << endl;
				cout << "====================================\n" << endl;
	            getch();
	            kurirlogin= {data_kurir[i]};
	            menu_kurir();
	            menu_login_kurir();
	            login="berhasil";
	        }
	    }
	    if (login != "berhasil"){
			setcolor(4);
	    	cout << "\nUsername atau password salah" << endl; getch();
		}
	}
}


void login_admin (){
	system("cls");
    string username,password,user_name,pass_word;
    username = "admin";
    password = "123" ;

    for (int i=0;i<3;i++){
		system("cls");
		setcolor(7);
		cout << "=====================================" << endl;
		cout <<	"              Login Admin            " << endl;
		cout << "=====================================\n" << endl;
        cout << "Masukan username : "; 
        fflush(stdin);getline(cin,user_name);
        cout << endl;
		setcolor(7);
        cout << "Masukan password : ";
        fflush(stdin);getline (cin , pass_word)     ;
        if (user_name == username && pass_word == password){
			setcolor(2);
			cout << "\n=====================================" << endl;
			cout <<	"          Anda berhasil login          " << endl;
			cout << "=====================================\n" << endl;
			getch();
            menu_manajemen_admin();
            break;
        }
        else if ( user_name != username  && pass_word != password){
			setcolor(4);
            cout << "\nUsername atau password yang anda masukan salah "; getch();
        }
    }

}

//========================================================================
int main(){

system("cls");
kelompok();
system("cls");

	int milih;
	open_file_paket();
	file_open_kurir();
    system("cls");
	setcolor(2);
	cout <<   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	setcolor(5);
	cout <<   "                  Decentralized Hub:                  " << endl;
	cout <<   "      Program Distribusi Paket di Kota Samarinda      " << endl;
	setcolor(2);
	cout <<   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;
	setcolor(7);
	cout <<  "\t\t======================" << endl
		<< 	 "\t\t     MENU LOGIN    	" << endl
		<<   "\t\t======================" << endl
		<<   "\t\t[1] Admin  		" << endl
		<<   "\t\t[2] Kurir 		" << endl
		<<   "\t\t[3] Keluar Program " << endl;
	do{
		setcolor(2);
		cout << "\n\t\tMasukkan Pilihan: "; cin >> milih;
	} while(eror(milih)==true);

    if (milih == 1){
        login_admin();
		getch();
		main();
    }
    else if ( milih == 2){
        menu_login_kurir();
		getch();
		main();
    }
    else if ( milih == 3){
        keluar_program();
		getch();
    }
    else {
		setcolor(4);
        cout << "\n\t\tMasukkan pilihan sesuai menu!!!"; getch();
        main();
    }
    
}
void menu_login_kurir(){ 
	system("cls");
	int pilih;
	setcolor(7);
	cout <<  "======================" << endl
		<< 	 "   MENU LOGIN KURIR   " << endl
		<<   "======================" << endl
		<<   "[1] Membuat Akun  	" << endl
		<<   "[2] Daftar Akun		" << endl
		<<   "[3] Login				" << endl
		<<   "[4] Kembali			" << endl;
	do{
		setcolor(2);
		cout << "\nMasukkan Pilihan: "; cin >> pilih;
	} while(eror(pilih)==true);
	switch(pilih){
		case 1:
			tambah_akun_kurir(data_kurir);
        	menu_login_kurir();
        	break;
        case 2:
        	daftar_akun_kurir(data_kurir);
        	menu_login_kurir();
        	break;
        case 3:
        	login_kurir();
        	menu_login_kurir();
        	break;
        case 4:
        	main();
        default:
			setcolor(4);
        	cout << "\nInput yang anda masukan salah!!! "; getch();
        	menu_login_kurir();
	}
}

void file_eksternal(){
	system("cls");
	int pilih;
	char yakin;
	setcolor(2);
	cout <<  "======================" << endl
		<< 	 "    MENU RESET FILE   " << endl
		<<   "======================" << endl
		<<   "[1] File Data Paket  		" << endl
		<<   "[2] File Data Kurir 		" << endl;
	do{
		setcolor(7);
		cout << "\nMasukkan Pilihan: "; cin >> pilih;
	} while(eror(pilih)==true);
	system("cls");
	if(pilih==1){
		setcolor(2);
		cout <<  "======================" << endl;
		cout << 	 "    MENU RESET FILE   " << endl;
		cout <<   "======================\n" << endl;
		setcolor(7);
		cout << "Apakah yakin ingin mereset data paket? [y/t] "; cin >> yakin;
			switch(yakin){
				case 'y':
					remove("data_paket.txt");
					cout << "\nFile data paket berhasil tereset!"; getch();
					break;
				case 't':
					cout << "\nFile data paket tidak tereset!"; getch();
					break;
					
				default:
					setcolor(4);
					cout << "Masukkan pilihan yang bener!!!"; getch();
			} menu_manajemen_admin();
	}
	else if(pilih==2){
		setcolor(2);
		cout <<  "======================" << endl;
		cout << 	 "    MENU RESET FILE   " << endl;
		cout <<   "======================\n" << endl;
		setcolor(7);
		cout << "Apakah yakin ingin mereset data kurir? [y/t] "; cin >> yakin;
			switch(yakin){
				case 'y':
					remove("data_kurir.txt");
					cout << "\nFile data paket berhasil tereset!"; getch();
					break;
				case 't':
					cout << "\nFile data paket tidak tereset!"; getch();
					break;
					
				default:
					setcolor(4);
					cout << "Masukkan pilihan yang bener"; getch();
			} menu_manajemen_admin();
	}
	else{
		setcolor(4);
		cout << "Masukkan pilihan yang bener!\n"; getch();
	}
}

void menu_manajemen_admin(){
	system("cls");
	int pilih;
	setcolor(7);
	cout <<  "======================" << endl
		<< 	 "     MENU MANAJEMEN   " << endl
		<<   "======================" << endl
		<<   "[1] Lihat Paket  		" << endl
		<<   "[2] Tambah Paket 		" << endl
		<<   "[3] Ubah Paket		" << endl
		<<   "[4] Cari Paket		" << endl
		<<   "[5] Daftar Kurir 		" << endl
		<<   "[6] Hapus Paket 		" << endl
		<<   "[7] Reset FIle		" << endl
		<<   "[8] Logout			" << endl
		<<   "[9] Keluar Program 	" << endl;
	do{
		setcolor(2);
		cout << "\nMasukkan Pilihan: "; cin >> pilih;
	} while(eror(pilih)==true);
	switch(pilih){
			case 1:
				tampilan_paket();
				menu_manajemen_admin();
				break;
			case 2:
				tambah_paket(penerima_paket);
				menu_manajemen_admin();
				break;
			case 3:
				ubah_datapaket();
				write_file_paket();
				menu_manajemen_admin();
				break;
			case 4:
				search();
				menu_manajemen_admin();
				break;
			case 5:
				daftar_kurir();
				menu_manajemen_admin();
				break;
			case 6:
				hapus_paket();
				write_file_paket();
				menu_manajemen_admin();
				break;
			case 7:
				file_eksternal();
				break;
			case 8:
				main();
			case 9:
				keluar_program(); // kondisi jika user memilih untuk keluar program
				break;
			default:
				setcolor(4);
				cout << "\nMasukkan pilihan sesuai menu"; getch();
				menu_manajemen_admin();
	
		}
}

