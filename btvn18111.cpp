#include <iostream>
#include <cstring>
using namespace std;

const int storage = 32 * 1024;
struct FileNode {
    string filename;
    int filesize;
    string time;
    FileNode* next;
};

struct List { FileNode* head; };
void init(List* l) { l->head = 0; }
void swap(string &a, string &b) { string tmp = a; a = b; b = tmp; }
void swap(int &a, int &b) { int t = a; a = b; b = t; }

FileNode* newfile(List* l, string name, int _size, string time) {
    FileNode* p = new FileNode();
    if (p == 0) return 0;
    p->filename = name;
    p->filesize = _size;
    p->time = time;
    p->next = nullptr;
    return p;
}

void addfile(List* l, string name, int _size, string time) {
    FileNode* p = newfile(l, name, _size, time);
    if (p == 0) return;
    if (l->head == 0) l->head = p;
    else {
        p->next = l->head;
        l->head = p;
    }
}

void arrangeFile_time(List* l) { // selection sort
    FileNode* tmp = l->head;
    while (tmp) {
        FileNode* min = tmp;
        FileNode* p = tmp->next;
        while (p) {
            if (p->time < min->time) {
                min = p;
            }
            p = p->next;
        }
        swap(min->filename, tmp->filename);
        swap(min->filesize, tmp->filesize);
        swap(min->time, tmp->time);
        tmp = tmp->next;
    }    
}

void arrangeFile_size(List* l) { // insertion sort
    FileNode* tmp = l->head;
    while (tmp) {
        FileNode* min = tmp;
        FileNode* p = tmp->next;
        while (p) {
            if (p->filesize < min->filesize) {
                min = p;
            }
            p = p->next;
        }
        swap(min->filename, tmp->filename);
        swap(min->filesize, tmp->filesize);
        swap(min->time, tmp->time);
        tmp = tmp->next;
    }    
}

int Sumsize(List* l) {
    FileNode* tmp = l->head;
    int s = 0;
    while (tmp) {
        s += tmp->filesize;
        tmp = tmp->next;
    }
    return s;
}

void copyFile(List* l1, List* l2, string name, int _size, string time) {
    FileNode* p = newfile(l2, name, _size, time);
    if (p == 0) return;
    FileNode* tmp = l1->head;
    if (l1->head == 0) l1->head = p;
    else {
        p->next = l1->head;
        l1->head = p;
    }
    arrangeFile_time(l1);
}

void deleteFile(List* l) {
    int sum = Sumsize(l);
    arrangeFile_size(l);
    if (sum <= storage) {
        cout << "Khong can xoa file do du dung luong";
        return;
    } else {
        FileNode* tmp = l->head;
        while (tmp && sum > storage) {
            sum -= tmp->filesize;
            FileNode* p = tmp->next;
            tmp = tmp->next;
            delete p;
        }
        cout << "Da xoa file";
    }

}
void printList(List* l) {
    FileNode* tmp = l->head;
    while (tmp) {
        cout << "File: " << tmp->filename << ", Size: " << tmp->filesize 
            << ", Time: " << tmp->time << endl;
        tmp = tmp->next;
    }
}


int main() {
    List document1;
    List document2;

    init(&document1);
    init(&document2); 

    addfile(&document1, "file1.txt", 1024, "2024-11-10");
    addfile(&document1, "file2.txt", 2048, "2024-11-09");
    addfile(&document1, "file3.txt", 512, "2024-11-11");

    copyFile(&document1, &document2, "file4.txt", 2048, "2024-11-04");
    deleteFile(&document1);
   

}