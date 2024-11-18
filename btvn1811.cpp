#include <iostream>
using namespace std;

struct Wordnode {
    char word[10];
    Wordnode* next;
};
struct List { Wordnode* head; };
void init(List* list) { list->head = 0; }

int str_length(const char* s) {
    int d = 0;
    while (s[d]) { d++; }
    return d;
}

bool str_cmp(char* str1, char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}


char* str_copy(char* s, const char* src){
    for(int i = 0; i < str_length(src); i++){
        s[i] = src[i];
    }
    s[str_length(src)] = 0;
    return s;
}

Wordnode* newnode(List* l, const char* word) {
    Wordnode* p = new Wordnode();
    if (p == nullptr) return 0;
    str_copy(p->word, word);
    p->next = nullptr;
    return p;
}

void addWord(List* l, const char* word) {
    Wordnode* p = newnode(l, word);
    if (p == nullptr) return;
    if (l->head == 0) l->head = p;
    else {
        Wordnode* tmp = l->head;
        while (tmp->next) { tmp = tmp->next; }
        tmp->next = p;
    }
}

char* findword(List* l) {
    Wordnode* tmp = l->head;
    int max = 0;
    char* wordmost = new char[10];
    while (tmp) {
        int c = 1;
        Wordnode* p = tmp->next;
        while (p) {
            if (str_cmp(tmp->word, p->word)) c++;
            p = p->next;
        }
        if (max < c) {
            max = c;
            str_copy(wordmost, tmp->word);
        }
        tmp = tmp->next;
    }
    return wordmost;
}

void deleteWord(List* l) {
    if (l->head == nullptr) {
        cout << "Danh sach rong, khong co tu lay." << endl;
        return;
    }

    while (l->head != nullptr && l->head->next != nullptr 
            && str_cmp(l->head->word, l->head->next->word)) {
        Wordnode* p = l->head;
        l->head = l->head->next;
        delete p;
    }

    Wordnode* tmp = l->head;
    while (tmp != nullptr && tmp->next != nullptr) {
        if (str_cmp(tmp->word, tmp->next->word)) {
            Wordnode* p = tmp->next;
            tmp->next = tmp->next->next;
            delete p;
        } else {
            tmp = tmp->next;  
        }
    }
}

int countWord(List* l) {
    int c = 0;
    if (l->head == nullptr) return 0;
    Wordnode* tmp = l->head;
    
    while (tmp != nullptr) {
        bool mark = true;
        Wordnode* p = tmp->next;
        while (p != nullptr) {
            if (str_cmp(tmp->word, p->word)) {
                mark = false;
                break;  
            }
            p = p->next;
        }
        if (mark) c++; 
        tmp = tmp->next;
    }
    return c;
}

void nhap(List* l) {
    int n;
    cout << "Nhập số từ: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        char word[10];
        cout << "Nhập từ thứ " << i + 1 << ": ";
        cin.getline(word, 10);
        addWord(l, word);
    }
}

void in(List* l) {
    Wordnode* tmp = l->head;
    while (tmp) {
        cout << tmp->word << ' ';
        tmp = tmp->next;
    }
}
int main() {
    List list;
    init(&list);
    nhap(&list);

    cout << findword(&list) << endl;
    deleteWord(&list);
    in(&list);
    cout << endl;
    cout << "Số từ vựng xuất hiện trong câu: " << countWord(&list);


}