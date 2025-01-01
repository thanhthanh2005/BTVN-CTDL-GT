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
void add_path(int data[n][n], string pr1, string pr2, int des) {
    string province[11] = { "HN", "ST", "TN", "BN", "BG", "UB", "HP",
                            "HD", "HY", "PL", "HB" };
    int m1, m2;
    for (int j = 0; j < 11; j++) {
        if (pr1 == province[j]) m1 = j;
        if (pr2 == province[j]) m2 = j;
    }
    data[m1][m2] = data[m2][m1] = des;
}

int main() {
    int data[n][n] = { 0 };
    add_path(data, "HN", "HD", 1);
    add_path(data, "HD", "HY", 2);
    add_path(data, "HY", "PL", 3);
    add_path(data, "HN", "PL", 4);
    add_path(data, "HN", "HB", 5);
    add_path(data, "HN", "ST", 6);
    add_path(data, "HN", "TN", 7);
    add_path(data, "HN", "BN", 8);
    add_path(data, "BN", "BG", 9);
    add_path(data, "BG", "UB", 10);
    add_path(data, "BN", "UB", 11);
    add_path(data, "UB", "HP", 12);
    add_path(data, "HP", "HD", 13);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
}