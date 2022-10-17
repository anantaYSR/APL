#include <iostream>
using namespace std;
int main(){

int matriks [5][5] = {
{1, 2, 3, 4, 5},
{2, 3, 4, 5, 6},
{3, 4, 5, 6, 7}, 
{4, 5, 6, 7, 8}, 
{5, 6, 7, 8, 9},
};

    for (int a =0; a < 5; a++)
    {
        for (int b=0; b < 5; b++)
        {
            cout << matriks [a][b] << " ";
        }
            cout << endl;
    }
}
