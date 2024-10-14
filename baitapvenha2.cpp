/*Số Blum là một số nguyên dương n có dạng tích của hai số nguyên tố phân biệt p và q, 
với cả p và q đều là các số nguyên tố Blum. Số nguyên tố Blum là các số nguyên tố 
có dạng 4k+3, trong đó k là một số nguyên không âm. 
Cụ thể, số Blum n được xác định như sau: n = p × q với p và q đều là số nguyên tố  dạng 4k+3*/

#include <iostream>
using namespace std;

void swap(int &a, int &b) { int t = a; a = b; b = t; }

bool checkprime(int n) {
    for (int i = 2; i * i <= (n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

bool checkblum(int n) { if ((n - 3) % 4 == 0 && checkprime(n)) return true; else return false; }

int main() {
    int n = 1000;
    int _size = 0;
    int a[n];

    int blum_number = 33; // Số blum cần tìm trong dãy
    int mark = 0; // Đánh dấu 

    // Tạo mảng số blum nhỏ hơn N cho trước
    for (int i = 3; i * i <= n; i += 1) {
        for (int j = i + 1; i * j <= n; j++) {
            if (checkblum(i) && checkblum(j)) {
                a[_size++] = i * j;
                if (blum_number == i * j) mark = 1;
            }
        }
    }

    // Sắp xếp dãy blum theo thứ tự tăng dần (insertsion sort)
    for (int i = 1; i < _size; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;       
        }
    }

    // Tìm các cặp số blum có tổng bằng N cho trước
    int low = 0;
    int high = _size - 1;
    int mark1 = 0;
    while (low < high) {
        int sum = a[low] + a[high];
        if (sum == n) {
            cout << a[low] << ' ' << a[high] << endl;
            mark1 = 1;
            low++;
            high--;
        }
        else if (sum < n) low++;
        else high--;
    }

    if (mark1 == 0) cout << "Khong tim thay cap so thoa man" << endl;
    if (mark == 0) cout << "So blum da cho khong co trong day";
    else cout << "So blum da cho co trong day";


}