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

bool str_cmp(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) { 
            return false; 
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
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
    if (l->head == 0) return p;
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


int main() {

}