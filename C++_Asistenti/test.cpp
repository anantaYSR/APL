#include "iostream"
using namespace std;
int main ()
{
    int i,j,baris,kolom;
    cout << "masukan baris" ; cin >> baris;
    cout << "masukan kolom" ; cin >> kolom; 

    int matriks[baris][kolom];
    cout << "masukan angka ke dalam matriks "<< endl;
    
    for (i=0;i<baris;i++)
    {
        for(j=0;j<kolom;j++)
        {
            cout << "baris "<< "kolom" << j+1 << ":"; cin>> matriks[i][j];
            
        }
    }
    cout << endl;
    for (i=0;i<baris;i++)
    {
        for(j=0;j<kolom;j++)
        {
            cout << matriks[i][j]<< " ";
        }
        cout << endl;
    }

}