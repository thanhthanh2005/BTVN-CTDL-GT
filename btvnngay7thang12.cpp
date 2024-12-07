/* Cài đặt cây biểu thức cho biểu thức và in ra 
    biểu thức theo các cách biểu diễn Trung tố, 
    hậu tố, và tiền tố. 
   Định nghĩa và khai báo các hàm sau:
   Cài đặt thuộc tính cho 1 node trên cây 
   Cài đặt hàm khởi tạo cây (không được bỏ qua 
 hàm kiểm tra rỗng)
   Cài đặt hàm nhập phần tử (bổ sung) vào cây 
   In các phần tử trên cây theo 3 giải thuật duyệt */

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left, *right;
};

Node* newnode(char data) {
    Node* p = new Node;
    p->data = data;
    p->left = p->right = nullptr;
    return p;
}

void initTree(Node*& root) {
    root = nullptr;
}

bool emptyTree(Node* root) {
    return root == nullptr;
}

Node* insert(Node* root, char data) {
    if (emptyTree(root)) {
        root = newnode(data);
        return root;
    }

    if (root->left == nullptr) {
        root->left = newnode(data);
    } else if (root->right == nullptr) {
        root->right = newnode(data);
    }
    return root;
}

void printInfix(Node* node) {
    if (node == nullptr) return;
    printInfix(node->left);  
    cout << node->data;      
    printInfix(node->right);
}

void printPostfix(Node* node) {
    if (node == nullptr) return;
    printPostfix(node->left);  
    printPostfix(node->right); 
    cout << node->data;      
}

void printPrefix(Node* node) {
    if (node == nullptr) return;
    cout << node->data;       
    printPrefix(node->left);  
    printPrefix(node->right); 
}

int main() {
    Node* root = nullptr;
    initTree(root);
    

    root = insert(root, '+');  
    root = insert(root, '-');  
    root = insert(root, '*');  
    root = insert(root->left, '5');  
    root = insert(root->left, 'a');  
    root = insert(root->right, 'b'); 
    root = insert(root->right, 'c'); 
    root = insert(root->right->right, '^'); 
    root = insert(root->right->right->right, '6'); 
    root = insert(root->right->right->right, '/'); 
    root = insert(root->right->right->right->right, 'd'); 
    root = insert(root->left->left, '(');  
    root = insert(root->left->left->left, 'h'); 
    root = insert(root->left->left->right, '-'); 
    root = insert(root->left->left->right->left, 'f'); 
    root = insert(root->left->left->right->right, ')'); 
    root = insert(root->right->right->right->right->right, '*'); 
    root = insert(root->right->right->right->right->right, 'e'); 
    root = insert(root->right->right->right->right->right->right, '^'); 
    root = insert(root->right->right->right->right->right->right->right, '1'); 
    root = insert(root->right->right->right->right->right->right->right, '2'); 

    printInfix(root);
    cout << endl;

    printPostfix(root);
    cout << endl;

    printPrefix(root);
    cout << endl;

    return 0;
}


