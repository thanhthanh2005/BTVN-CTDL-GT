#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* newnode(int data) {
    Node* p = new Node;
    p->data = data;
    p->height = 1;
    p->left = p->right = nullptr;
    return p;
}

int height(Node* T) {
    if (T == nullptr) return -1;
    return T->height;
}

void updateHeight(Node* t) {
    t->height = 1 + max(height(t->left), height(t->right));
}

void rotateRight(Node*& t) {
    Node* tmp1 = t->left;
    Node* tmp2 = tmp1->right;
    tmp1->right = t;
    t->left = tmp2;
    updateHeight(t);
    updateHeight(tmp1);
    t = tmp1;
}

void rotateLeft(Node*& t) {
    Node* tmp1 = t->right;
    Node* tmp2 = tmp1->left;
    tmp1->left = t;
    t->right = tmp2;
    updateHeight(t);
    updateHeight(tmp1);
    t = tmp1;
}

void doubleRotateRight(Node*& t) {
    rotateLeft(t->left);
    rotateRight(t);
}

void doubleRotateLeft(Node*& t) {
    rotateRight(t->right);
    rotateLeft(t);
}

int updateBalance(Node* T) {
    if (T == nullptr) return 0;
    else return height(T->left) - height(T->right);
}

void balance(Node*& node) {
    if (!node) return;

    updateHeight(node);
    int b = updateBalance(node);

    if (b > 1) { 
        if (updateBalance(node->left) >= 0)
            rotateRight(node); 
        else
            doubleRotateRight(node); 
    } else if (b < -1) { 
        if (updateBalance(node->right) <= 0)
            rotateLeft(node); 
        else
            doubleRotateLeft(node); 
    }
}

void insert(Node*& node, int data) {
    if (node == nullptr) {
        node = newnode(data);
        return;
    }

    if (data <= node->data)
        insert(node->left, data);
    else if (data > node->data)
        insert(node->right, data);

    balance(node); 
}

void print(Node* t) {
    if (t != nullptr) {
        cout << t->data << " ";
        print(t->left);
        print(t->right);
    }
}

int main() {
    Node* root = nullptr;
    
    insert(root, 17);
    insert(root, 23);
    insert(root, 201);
    insert(root, 98);
    insert(root, 67);
    insert(root, 83);
    insert(root, 13);
    insert(root, 23);
    insert(root, 10);
    insert(root, 191);
    insert(root, 84);
    insert(root, 58);

    print(root);

}
