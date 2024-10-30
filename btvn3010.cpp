#include <iostream>
using namespace std;

struct Node {
    int heso;
    int somu;
    Node* next;
};

void khoitao(Node*& head) {
    head = nullptr;
}

Node* TaoNodeMoi(int heso, int somu) {
    Node* p = new Node();
    if (heso == 0) {
        delete p;
        cout << "Da giai phong cap phat phan tu nay do he so = 0\n";
        return nullptr;
    }
    p->heso = heso;
    p->somu = somu;
    p->next = nullptr;
    return p;
}

void ChenNodeVaoDanhSach(int heso, int somu, Node*& head) {
    Node* p = TaoNodeMoi(heso, somu);
    if (p == nullptr) return;
    Node* tmp = head;
    if (head == nullptr) head = p;
    else {
        while (tmp->next != nullptr) tmp = tmp->next;
        tmp->next = p;
    }
}

void NhapDathuc(Node*& head) {
    int bac, heso;
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    for (int somu = bac; somu >= 0; somu--) {
        cout << "Nhap he so cua x^" << somu << ':';
        cin >> heso;
        ChenNodeVaoDanhSach(heso, somu, head);
    }
}

void InDathuc(Node*& head) {
    Node* tmp = head;
    while (tmp != NULL) {
        if (tmp->somu != 0) {
            cout << tmp->heso << "x^" << tmp->somu;
            if (tmp->next != NULL) cout << " + ";
            tmp = tmp->next;
        } else {
            cout << tmp->heso;
            tmp = tmp->next;
        }
    }
    cout << endl;
}

int main() {
    Node* head;
    khoitao(head);
    NhapDathuc(head);
    InDathuc(head);
}