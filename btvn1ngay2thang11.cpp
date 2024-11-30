// Trong siêu thị người ta xếp hàng để thực hiện thanh toán. Mỗi giỏ hàng với các hàng hoá được coi 
// như một node trong một cấu trúc hàng đợi.

//  Khai báo cấu trúc hàng đợi. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung 
// sau được thực hiện 
//  Loại bỏ từng người ra khỏi hàng đợi sau khi người đó đã thực hiện thanh toán xong 
//  Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên làm việc
//  Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân. 

// Coi hàng hóa trong giỏ hàng cũng như 1 node và triển khai các hàng hóa trong giỏ như queue
// Giả sử các hàng hóa trong 1 giỏ hàng được mua trước sẽ được thanh toán trước
#include <iostream>
using namespace std;

int MAX_cart = 100;
int MAX_product_in_cart = 20;

struct product {
    int code_product;  // ma san pham
    int price;  // gia san pham
    product* next;
};
struct cart {
    product* front;
    product* rear;
    int numbers_of_product;
    cart* next;
};
struct queue_cart {
    cart* front;
    cart* rear;
    int numbers_of_cart;
};

void init(queue_cart* qc) {
    qc->front = qc->rear = 0;
    qc->numbers_of_cart = 0;
}
bool cart_empty(queue_cart* qc) { return qc->front == 0; }
bool cart_full(queue_cart* qc) { return qc->numbers_of_cart == MAX_cart; }

bool product_empty_in_cart(cart* crt) { return crt->front == 0; }
bool product_full_in_cart(cart* crt) { return crt->numbers_of_product == MAX_product_in_cart; }

product* newproduct(int code, int price) {  // tạo sản phẩm mới
    product* pr = new product;
    pr->code_product = code;
    pr->price = price;
    pr->next = nullptr;
    return pr;
}

cart* newcart() {   // tạo giỏ mới
    cart* crt = new cart;
    crt->front = crt->rear = nullptr;
    crt->numbers_of_product = 0;
    crt->next = nullptr;
    return crt;
}

void enqueue_cart(queue_cart* qc) {   // thêm giỏ mới vào queue
    if (cart_full(qc)) {
        cout << "Khong the them gio hang" << endl;
    } else {
        cart* crt = newcart();  
        if (cart_empty(qc)) qc->front = qc->rear = crt;
        else {
            qc->rear->next = crt;
            qc->rear = crt;
        }
        qc->numbers_of_cart++;   
    }
}

void enqueue_product_in_cart(cart* crt, int c, int p) {  // thêm sản phẩm vào giỏ
    if (/*crt == nullptr ||*/ product_full_in_cart(crt)) {
        cout << "Khong the them san pham" << endl;
        return;
    } else {
        product* pr = newproduct(c, p);
        if (crt->front == 0) crt->front = crt->rear = pr;
        else {
            crt->rear->next = pr;
            crt->rear = pr;
        }
    }
    crt->numbers_of_product++;
}

int count_product(queue_cart* qc) {  // dem so luong san pham A da mua
    int count = 0;
    int code_pr = 2024;   // ma san pham A
    cart* tmp_crt = qc->front;
    while (tmp_crt) {
        product* tmp_pr = tmp_crt->front;
        while (tmp_pr) {
            if (tmp_pr->code_product == code_pr) count++;
            tmp_pr = tmp_pr->next;
        }
        tmp_crt = tmp_crt->next;
    }
    return count;
}

int price_cart(cart* crt) {
    if (product_empty_in_cart(crt)) {
        return -1;
    } else {
        int p = 0;
        product* tmp = crt->front;
        while (tmp) {
            p+= tmp->price;
            tmp = tmp->next;
        }
        return p;
    }
}

int price_queuecart(queue_cart* qc) {
    if (cart_empty(qc)) {
        cout << "Không có giỏ hàng để thanh toán";
        return -1;
    } else {
        int p = 0;
        cart* crt = qc->front;
        while (crt) {
            p += price_cart(crt);
            crt = crt->next;
        }
        return p;
    }
}

void dequeue_product_in_cart(cart* crt) {    // xóa sản phẩm khỏi queue trong giỏ
    if (/*crt == nullptr || */product_empty_in_cart(crt)) {
        cout << "Khong co san pham trong gio de xoa" << endl;
    } else {
        product* tmp = crt->front;
        crt->front = crt->front->next;
        if (crt->front == 0) crt->rear = 0;
        delete tmp;
        crt->numbers_of_product--;
    }
}

bool payment_is_successful(cart* crt) {   // kiểm tra thanh toán thành công
    if (product_empty_in_cart(crt)) {
        cout << "Khong co san pham de thanh toan" << endl;
        return false;
    } 
    while (!product_empty_in_cart(crt)) {
        dequeue_product_in_cart(crt);
    }
    //cout << "gio hang duoc thanh toan" << endl;
    return true;  
}

void dequeue_cart(queue_cart* qc) {   // loại bỏ giỏ hàng khi thanh toán xong
    if (cart_empty(qc)) {
        cout << "Khong co gio hang de loai bo" << endl;
        return;
    } else {
        cart* tmp = qc->front;
        if (payment_is_successful(tmp)) {
            qc->numbers_of_cart--;
            qc->front = qc->front->next;
            if (qc->front == nullptr) qc->rear = nullptr;
            delete tmp;
        } else {
            cout << "thanh toan khong thanh cong" << endl;
            return;
        }
    }
}

void payment_queuecart(queue_cart* qc) {
    if (cart_empty(qc)) {
        cout << "Khong co gio hang de thanh toan";
        return;
    } else {
        while (!cart_empty(qc)) {
            dequeue_cart(qc);
        }
        cout << "Tat ca gio hang duoc thanh ";
    }
} 

void input_cart(queue_cart* qc) {
    int nums_of_cart;
    cout << "Số giỏ hàng cần được thanh toán: ";
    cin >> nums_of_cart;
    for (int i = 1; i <= nums_of_cart; i++) {
        enqueue_cart(qc);
        cart* crt = qc->rear;
        cout << "Số sản phẩm trong giỏ hàng " << i << ": ";
        int nums_of_product;
        cin >> nums_of_product;
        for (int j = 1; j <= nums_of_product; j++) {
            int code_pr, price_pr;
            cout << "Mã sản phẩm " << j << ": ";
            cin >> code_pr;
            cout << endl;
            cout << "Giá sản phẩm " << j << ": ";
            cin >> price_pr;
            cout << endl;
            enqueue_product_in_cart(crt, code_pr, price_pr);
        }
    }
}

int main() {
    queue_cart qc;
    init(&qc);

    input_cart(&qc);

    cout << "Số lượng sản phẩm A đã mua: " << count_product(&qc) << endl;
    cout << "Tổng số tiền thu được: " << price_queuecart(&qc) << endl;
    payment_queuecart(&qc);


    //enqueue_cart(&qc);
    
    //enqueue_product_in_cart(qc.front, 2024, 100);
    //enqueue_product_in_cart(qc.front, 2024, 200);
    //cout << qc.numbers_of_cart << endl;
    //cout << qc.front->numbers_of_product;
    //enqueue_product_in_cart(qc.front->next, 2024, 100);
    //dequeue_cart(&qc);
    //cout << qc.front->numbers_of_product;
}