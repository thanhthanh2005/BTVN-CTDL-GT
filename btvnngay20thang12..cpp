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
    int page_start;   // Trang mở đầu
    Node* section[MAX];  // Các mục con 
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
    p->page_start = n;
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

void addChapter(const char* t, int n, Book* b, Node* s) {
    Node* p = newsection(t, n);
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

void chapter_longest(Book* b) {
	int max = 0;
	const char* title;
	int c = countchapter(b);
	for (int i = 0; i < c; i++) {
		if (b->root->section[i + 1] != nullptr) {
		    int m = b->root->section[i + 1]->page_start - b->root->section[i]->page_start;
		    if (m > max) {
			    max = m;
			    title = b->root->section[i]->title;
		    }
	    } 
	}
	cout << "Chapter is the longest : " << title << endl;
	cout << max; 
}

bool find_section(Node* s, const char* title) {
	if (s == nullptr) return false;
	for (int i = 0; i < MAX; i++) {
		if (s->section[i]) {
			if (s->section[i]->title == title) return true;
			if (find_section(s->section[i], title)) return true;
		}
	}
	return false;
}

int main() {
	Book book;
	init(&book);
    addBook("CTDL&GT", &book);
	addChapter("Chuong 1", 1,  &book, book.root);
    addSection("Muc 1.1", 1, book.root->section[0]);
	addSection("Muc 1.1.1", 3, book.root->section[0]->section[0]);
	addSection("Muc 1.1.2", 4, book.root->section[0]->section[0]);
	addSection("Muc 1.2", 5, book.root->section[0]);
	addSection("Muc 1.2.1", 6, book.root->section[0]->section[1]);
	addSection("Muc 1.2.2", 7, book.root->section[0]->section[1]);

	addChapter("Chuong 2", 30, &book, book.root);
	addSection("Muc 2.1", 30, book.root->section[1]);
	addSection("Muc 2.2", 35, book.root->section[1]);
	addSection("Muc 2.3", 40, book.root->section[1]);

	addChapter("Chuong 3", 50, &book, book.root);
	addSection("Muc 3.1", 55, book.root->section[2]);
	addSection("Muc 3.2", 60, book.root->section[2]);
	
	addChapter("Chuong 4", 80, &book, book.root);
	addSection("Muc 4.1", 85, book.root->section[3]);
	
    //cout << "Numbers of chapter: " << countchapter(&book) << endl;
	//chapter_longest(&book);
	cout << find_section(book.root, "Muc 2.1.2.3");
}