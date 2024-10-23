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
    cout << "So nguoi sinh it nhat trong 1 nam: " << m << " Cac nam cung so nguoi sinh: ";
    while (a[i].soluongnguoi == m && i < sonam) {
        cout << a[i].namsinh << ' ';
        i++;
    }
    cout << endl;
    int n = a[j].soluongnguoi;
    cout << "So nguoi sinh nhieu nhat trong 1 nam: " << n << " Cac nam cung so nguoi sinh: ";
    while (a[j].soluongnguoi == n && j >= 0) {
        cout << a[j].namsinh << ' ';
        j--;
    }

}

int main() {
    int sonam = 11;
    danso a[sonam] = { {1920, 30}, {1921, 11}, {1922, 26}, {1923, 30}, {1924, 35}, {1925, 40},
                       {1926, 26}, {1927, 0}, {1928, 70}, {1929, 60}, {1930, 11} };

    Sapxep(a, 0, sonam - 1);
    
    Task1(a, sonam);
    Task2(a, sonam);
    

}