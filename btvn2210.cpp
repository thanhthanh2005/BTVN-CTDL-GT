#include <iostream>
using namespace std;

struct danso {
	int namsinh;
	int soluongnguoi;
};

void nhap(danso a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i].namsinh >> a[i].soluongnguoi;
	}
}

void swap(danso &a, danso &b) { danso tmp = a; a = b; b = tmp; }

void Sapxep(danso a[], int l, int r) {
    if (l >= r) return;
    int i = l + 1, j = r;
    while (i <= j) {
        while (a[i].soluongnguoi < a[l].soluongnguoi && i <= j) i++;
        while (a[j].soluongnguoi >= a[l].soluongnguoi && i <= j) j--;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    Sapxep(a, l, j - 1);
    Sapxep(a, j + 1, r);
}

int main() {
    int sonam = 11;
    danso a[sonam] = { {1920, 30}, {1921, 11}, {1922, 26}, {1923, 30}, {1924, 35}, {1925, 40},
                       {1926, 26}, {1927, 0}, {1928, 70}, {1929, 60}, {1930, 11} };

    Sapxep(a, 0, sonam - 1);
    
    int i = 0;
    while (i < sonam) {
        if (a[i].soluongnguoi != a[i + 1].soluongnguoi) {
            cout << "So luong nguoi: " << a[i].soluongnguoi
                 << " Cac nam cung so luong nguoi sinh: " << a[i].namsinh << ' ' << endl;
            i++;
        } else {
        cout << "So luong nguoi: " << a[i].soluongnguoi
             << " Cac nam cung so luong nguoi sinh: " << a[i].namsinh << ' ';
        while (a[i].soluongnguoi == a[i + 1].soluongnguoi) {
            ++i;
            cout << a[i].namsinh << ' ';
        }
        cout << endl;
        i++;
    } }

}