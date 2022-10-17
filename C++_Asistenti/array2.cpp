#include "iostream"
using namespace std;
int main ()

{
    string nilai [10];
        cout << " masukan nilai " << endl;
        nilai  [0] = "ganteng";
        nilai  [1] = "tapi";
        nilai  [2] = "ananta";
        nilai  [3] = " nice";
        
        for(int x= 0; x<4;x++)
        {
            cout << "nilai : " << nilai[x] << endl;
        }

        return 0;
}

