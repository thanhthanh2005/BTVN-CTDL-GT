/*Mục lục của một cuốn sách được lưu trữ dưới dạng một cây trong đó mỗi node có thể là chapter, 
section, subsection, subsubsection.  
 Khai báo cấu trúc cây để biểu diễn cuốn sách. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để 
đảm bảo các nội dung sau được thực hiện:  
 Xác định số chương của cuốn sách 
 Tìm chương dài nhất của cuốn sách 
 Thực hiện tìm một mục và xoá mục đó khỏi sách. Lưu ý cập nhật lại số trang của từng mục.  */

#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    const char* title;
    int nums_page;
    Node* section[MAX];
};

struct Book {
    Node* root;
};

void init(Book* b) { b->root = nullptr; }

bool book_empty(Book* b) { return b->root == nullptr; }

Node* newbook(const char* title) {
    Node* p = new Node;
    p->title = title;
    for (int i = 0; i < MAX; i++) {
        p->section[i] = nullptr;
    }
    return p;
}

Node* newsection(const char* t, int n) {
    Node* p = new Node;
    p->nums_page = n;
    p->title = t;
    for (int i = 0; i < MAX; i++) {
        p->section[i] = nullptr;
    }
    return p;
}

Node* newchapter(const char* t) {
	Node* p = new Node;
	p->title = t;
	for (int i = 0; i < MAX; i++) {
		p->section[i] = nullptr;
	}
	return p;
}

void addBook(const char* t, Book* b) {
    if (book_empty(b)) {
        b->root = newbook(t);
        return;
    }
}

void addChapter(const char* t, Book* b, Node* s) {
    Node* p = newchapter(t);
    for (int i = 0; i < MAX; i++) {
    	if (s->section[i] == nullptr) {
    		s->section[i] = p;
            return;
	    }
    }
	cout << "Khong the them chapter";
}

void addSection(const char* t, int n, Node* s) {
    if (s == nullptr) return;
	for (int i = 0; i < MAX; i++) {
		if (s->section[i] == nullptr) {
			s->section[i] = newsection(t, n);
			return;
		}
	}
	cout << "Khong the them section";
}

int countchapter(Book* b) {
	int c = 0;
	for (int i = 0; i < MAX; i++) {
        if (b->root->section[i] != nullptr) {
            c++;
        } else break; 
    }
    return c;
}

int pages_of_chapter(Node* s) {
    

}

int main() {
	Book book;
	init(&book);
    addBook("CTDL&GT", &book);
	addChapter("Chuong 1", &book, book.root);
	addChapter("Chuong 2", &book, book.root);
	addChapter("Chuong 3", &book, book.root);
	addChapter("Chuong 4", &book, book.root);
	
	addSection("Muc 1.1", 20, book.root->section[0]);
	addSection("Muc 1.2", 19, book.root->section[0]);
	addSection("Muc 2.1", 18, book.root->section[1]);
	addSection("Muc 2.2", 17, book.root->section[1]);
	addSection("Muc 2.3", 16, book.root->section[1]);
	addSection("Muc 3.1", 15, book.root->section[2]);
	addSection("Muc 3.2", 14, book.root->section[2]);
	addSection("Muc 4.1", 13, book.root->section[3]);
	
	cout << countchapter(&book) << endl;
}