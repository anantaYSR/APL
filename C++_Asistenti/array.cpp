#include "iostream"
using namespace std;
int main (){

    int matriks[3][3] ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (int a; a < 3; a++) {
        for (int b; b < 3; b++){
            cout << matriks[a][b] << "   ";

        } 
        cout << endl;
    }

}

