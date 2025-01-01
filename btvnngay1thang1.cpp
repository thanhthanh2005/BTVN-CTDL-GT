#include <iostream>
#include <cstring>
using namespace std;

/* 
HN-HD : D1
HD-HY : D2
HY-PL : D3
HN-PL : D4
HN-HB : D5
HN-ST : D6
HN-TN : D7
HN-BN : D8
BN-BG : D9
BG-UB : D10
BN-UB : D11
UB-HP : D12
HP-HD : D13
*/

const int n = 11;

int main() {
    int data[n][n] = { 0 };
    string province[11] = { "HN", "ST", "TN", "BN", "BG", "UB", "HP",
                            "HD", "HY", "PL", "HB" };
    for (int i = 1; i <= 13; i++) {
        
        string pr1, pr2;
        cin >> pr1 >> pr2;
        int m1, m2;
        for (int j = 0; j < 11; j++) {
            if (pr1 == province[j]) m1 = j;
            if (pr2 == province[j]) m2 = j;
        }
        data[m1][m2] = data[m2][m1] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
}