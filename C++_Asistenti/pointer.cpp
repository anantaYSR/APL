#include "iostream"
using namespace std;
int tambah(int nilai1, int nilai2) {
    return nilai1 + nilai2;
}
void masuk() {
    int hasil = tambah(2,3);
    cout << "hasil dari 2 + 3 =" << hasil;
}
int main (){

    
    masuk();
    return 0;
}