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
    if (p == nullptr) return nullptr;
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

void XoaPT(Node*& head) {
    Node* p = head;
    while (p) {
        if (p->heso == 0) {
            Node* tmp = p;
            
        }
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