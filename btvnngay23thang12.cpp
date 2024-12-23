#include <iostream> 
using namespace std; 

struct Node { 
    int data; 
    Node *left; 
    Node *right; 
    int height; 
};

Node* newnode(int data) {
	Node* p = new Node;
	p->data = data;
	p->height = 1;
	p->left = p->right = nullptr;
	return p;
} 


int height(Node *T) { 
    if (T == nullptr) return -1; 
    return T->height; 
} 

void updateHeight(Node* t) {
	t->height = 1 + max(height(t->left), height(t->right)); 
}

Node* rightRotate(Node *t) { 
    Node *tmp1 = t->left; 
    Node *tmp2 = tmp1->right; 
    tmp1->right = t; 
    t->left = tmp2;  
    updateHeight(t);
    updateHeight(tmp1);
    return tmp1; 
} 


Node *leftRotate(Node *t) { 
    Node *tmp1 = t->right; 
    Node *tmp2 = tmp1->left; 
    tmp1->left = t; 
    t->right = tmp2;  
    updateHeight(t);
    updateHeight(tmp1);
    return tmp1; 
} 

int getBalance(Node* T) { 
    if (T == nullptr) return 0; 
    else return height(T->left) - height(T->right); 
} 


Node* insert(Node* node, int data) { 

    if (node == nullptr) return newnode(data); 

    if (data <= node->data) node->left = insert(node->left, data); 
    else if (data > node->data) node->right = insert(node->right, data); 
    else return node; 
    
    updateHeight(node);

    int balance = getBalance(node); 

    if (balance > 1 && data < node->left->data) 
        return rightRotate(node); 

    if (balance < -1 && data > node->right->data) 
        return leftRotate(node); 

    if (balance > 1 && data > node->left->data) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 
    if (balance < -1 && data < node->right->data) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
    return node; 
} 
 
void print(Node *t) { 
    if (t != nullptr) { 
        cout << t->data << " "; 
        print(t->left); 
        print(t->right); 
    } 
} 

int main() { 
    Node *root = nullptr; 
    
    root = insert(root, 17); 
    root = insert(root, 23); 
    root = insert(root, 201); 
    root = insert(root, 98); 
    root = insert(root, 67); 
    root = insert(root, 83);
	root = insert(root, 13); 
	root = insert(root, 23); 
	root = insert(root, 10); 
	root = insert(root, 191); 
	root = insert(root, 84); 
	root = insert(root, 58);  
    
    print(root); 
    
    return 0; 
}