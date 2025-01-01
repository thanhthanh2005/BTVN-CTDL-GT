#include <iostream>
using namespace std;

string province[11] = { "HN", "ST", "TN", "BN", "BG", "UB", "HP",
                            "HD", "HY", "PL", "HB" };

struct Node {
    int position;
    int dst;
    Node* link;

    Node(int p, int dst) : position(p), dst(dst), link(nullptr) {};
};

void addNode(Node*& node, int p, int dst) {
    if (node == nullptr) {
        node = new Node(p, dst);
        return;
    }
    Node* tmp = node;
    while (tmp->link) {
        tmp = tmp->link;
    }
    tmp->link = new Node(p, dst);
}

void printGraph(Node* node) {
    cout << node->position << ':';
    while (node->link) {
        cout << node->link->position
            << '(' << node->link->dst << ')' << ' ';
        node = node->link;
    }
    cout << endl;
}


int main() {
    Node* graph[11] = { nullptr };
    for (int i = 0; i < 11; i++) {
        addNode(graph[i], i, 0);
    }
    
    addNode(graph[0], 1, 6);
    addNode(graph[0], 2, 7);
    addNode(graph[0], 3, 8);
    addNode(graph[0], 7, 1);
    addNode(graph[0], 9, 4);
    addNode(graph[0], 10, 5);    

    addNode(graph[1], 0, 6);

    addNode(graph[2], 0, 7);

    addNode(graph[3], 0, 8);
    addNode(graph[3], 4, 9);
    addNode(graph[3], 5, 11);

    addNode(graph[4], 3, 9);
    addNode(graph[4], 5, 10);

    addNode(graph[5], 4, 10);
    addNode(graph[5], 3, 11);
    addNode(graph[5], 6, 12);

    addNode(graph[6], 5, 12);
    addNode(graph[6], 7, 13);

    addNode(graph[7], 0, 1);
    addNode(graph[7], 8, 2);
    addNode(graph[7], 6, 13);

    addNode(graph[8], 7, 2);
    addNode(graph[8], 9, 3);
    
    addNode(graph[9], 0, 4);
    addNode(graph[9], 8, 3);

    addNode(graph[10], 0, 5);

    for (int i = 0; i < 11; i++) {
        printGraph(graph[i]);
    }


}