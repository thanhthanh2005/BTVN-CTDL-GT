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

void Lietke(danso a[], int sonam, int index) {

}

void Task1(danso a[], int sonam) {
    int i = 0;
    while (i < sonam) {
        int m = a[i].soluongnguoi;
        cout << "So luong nguoi: " << m << " Cac nam cung so nguoi sinh: ";
        while (a[i].soluongnguoi == m) {
            cout << a[i].namsinh << ' ';
            i++;
        }
        cout << endl;
    }
}

void Task2(danso a[], int sonam) {
    int i = 0, j = sonam - 1;
    int m = a[i].soluongnguoi;
    cout << "Số người sinh ít nhất trong 1 năm: " << m << " Các năm có cùng số người sinh: ";
    while (a[i].soluongnguoi == m && i < sonam && i >= 0) {
        cout << a[i].namsinh << ' ';
        i++;
    }
    cout << endl;
    int n = a[j].soluongnguoi;
    cout << "Số người sinh nhiều nhất trong 1 năm: " << n << " Các năm có cùng số người sinh: ";
    while (a[j].soluongnguoi == n && j >= 0 && j < sonam) {
        cout << a[j].namsinh << ' ';
        j--;
    }

}

int main() {
    int sonam = 51;
    danso a[sonam];
    // danso a[sonam] = { {1920, 30}, {1921, 11}, {1922, 26}, {1923, 30}, {1924, 35}, {1925, 40},
    //                    {1926, 26}, {1927, 0}, {1928, 70}, {1929, 60}, {1930, 11} };
    nhap(a, sonam);  
    Sapxep(a, 0, sonam - 1);
    Task1(a, sonam);  // Liệt kê các năm có cùng số người sinh
    Task2(a, sonam);  // Liệt kê các năm có số người sinh ít nhất và nhiều nhất
    

}