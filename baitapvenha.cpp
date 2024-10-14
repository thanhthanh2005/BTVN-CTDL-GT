#include <iostream>
using namespace std;

void swap(const char* &a, const char* &b) {
    const char* tmp = a;
    a = b;
    b = tmp;
}

bool str_cmp(const char* s1, const char* s2) {
    while (*s1 != 0 && *s2 != 0) {
        if (*s1 != *s2) return false;
        *s1++;
        *s2++;
    }
    return true;
}

int mahoa(const char* s) {
    if (str_cmp(s, "do") == 1) return 0;
    else if (str_cmp(s, "trang") == 1) return 1;
    else return 2; 
}


int main() {
    int n = 8;
    const char* input[n] = { "xanh", "do", "trang", "do", "xanh", "trang", "do", "do" };

    // Insertion sort
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && mahoa(input[j]) < mahoa(input[j - 1])) {
            swap(input[j], input[j - 1]);
            j--;       
        }
    }

    for (int i = 0; i < n; i++) cout << input[i] << ' ';    
}