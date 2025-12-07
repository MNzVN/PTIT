#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Book {
private:
    string bookId;
    string bookName;
    float price;
    string author;
    int quantity;
    bool status;
public:
    Book() {}

    Book(string bookId, string bookName, float price, string author, int quantity, bool status) {
        this->bookId = bookId;
        this->bookName = bookName;
        this->price = price;
        this->author = author;
        this->quantity = quantity;
        this->status = status;
    }

    string getBookId() { return this->bookId; }
    void setBookId(string bookId) { this->bookId = bookId; }

    string getBookName() { return this->bookName; }
    void setBookName(string bookName) { this->bookName = bookName; }

    float getPrice() { return this->price; }
    void setPrice(float price) { this->price = price; }

    string getAuthor() { return this->author; }
    void setAuthor(string author) { this->author = author; }

    int getQuantity() { return this->quantity; }
    void setQuantity(int quantity) { this->quantity = quantity; }

    bool getStatus() { return this->status; }
    void setStatus(bool status) { this->status = status; }

    void inputData() {
        cin.ignore();

        cout << "Nhap ma sach: ";
        getline(cin, this->bookId);

        cout << "Nhap ten sach: ";
        getline(cin, this->bookName);

        cout << "Nhap gia sach: ";
        cin >> this->price;
        cin.ignore();

        cout << "Nhap ten tac gia: ";
        getline(cin, this->author);

        cout << "Nhap so luong: ";
        cin >> this->quantity;

        cout << "Nhap trang thai (1: Dang ban, 0: Dung ban): ";
        cin >> this->status;
    }

    void displayData() {
        cout << "---------------------------------\n";
        cout << "Ma sach: " << this->bookId << " - Ten sach: " << this->bookName << endl;
        cout << "Gia: " << this->price << " - Tac gia: " << this->author << endl;
        cout << "So luong: " << this->quantity
             << " - Trang thai: " << (this->status ? "Dang ban" : "Dung ban") << endl;
    }
};
Book arrBooks[100];
int currentIndex = 0;
void displayListBook();
void addBook();
int findIndexById(string bookId);
void updateBook();
void deleteBook();
void findBookByName();
void findBookByPriceRange();
void sortBookByPriceASC();
int main() {
    do {
        cout << "\n--- QUAN LY SACH ---\n";
        cout << "1. Danh sach sach\n";
        cout << "2. Them moi sach\n";
        cout << "3. Cap nhat sach\n";
        cout << "4. Xoa sach\n";
        cout << "5. Tim kiem sach theo ten\n";
        cout << "6. Tim kiem sach theo khoang gia\n";
        cout << "7. Sap xep sach theo gia tang dan\n";
        cout << "8. Thoat\n";
        cout << "Nhap lua chon cua ban: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: displayListBook(); break;
            case 2: addBook(); break;
            case 3: updateBook(); break;
            case 4: deleteBook(); break;
            case 5: findBookByName(); break;
            case 6: findBookByPriceRange(); break;
            case 7: sortBookByPriceASC(); break;
            case 8: exit(0);
            default: cout << "Vui long chon tu 1-8\n";
        }
    } while (true);
}
void displayListBook() {
    if (currentIndex == 0) {
        cout << "Chua co du lieu sach!\n";
        return;
    }
    for (int i = 0; i < currentIndex; i++)
        arrBooks[i].displayData();
}
void addBook() {
    arrBooks[currentIndex].inputData();
    currentIndex++;
}
int findIndexById(string bookId) {
    for (int i = 0; i < currentIndex; i++) {
        if (arrBooks[i].getBookId() == bookId)
            return i;
    }
    return -1;
}
void updateBook() {
    cin.ignore();
    cout << "Nhap ma sach can cap nhat: ";
    string bookId;
    getline(cin, bookId);

    int index = findIndexById(bookId);
    if (index == -1) {
        cout << "Ma sach khong ton tai!\n";
        return;
    }
    bool isExit = true;
    do {
        cout << "\n1. Cap nhat ten sach\n";
        cout << "2. Cap nhat gia sach\n";
        cout << "3. Cap nhat tac gia\n";
        cout << "4. Cap nhat so luong\n";
        cout << "5. Cap nhat trang thai\n";
        cout << "6. Thoat\n";
        cout << "Lua chon: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cin.ignore();
                string bookName;
                cout << "Nhap ten moi: ";
                getline(cin, bookName);
                arrBooks[index].setBookName(bookName);
                break;
            }
            case 2: {
                float price;
                cout << "Nhap gia moi: ";
                cin >> price;
                arrBooks[index].setPrice(price);
                break;
            }
            case 3: {
                cin.ignore();
                string author;
                cout << "Nhap tac gia moi: ";
                getline(cin, author);
                arrBooks[index].setAuthor(author);
                break;
            }
            case 4: {
                int quantity;
                cout << "Nhap so luong moi: ";
                cin >> quantity;
                arrBooks[index].setQuantity(quantity);
                break;
            }
            case 5: {
                bool status;
                cout << "Nhap trang thai moi (1/0): ";
                cin >> status;
                arrBooks[index].setStatus(status);
                break;
            }
            case 6:
                isExit = false;
                break;
            default:
                cout << "Vui long chon 1-6!\n";
        }
    } while (isExit);
}
void deleteBook() {
    cout << "Nhap ma sach can xoa: ";
    string bookId;
    cin >> bookId;

    int index = findIndexById(bookId);
    if (index == -1) {
        cout << "Ma sach khong ton tai!\n";
        return;
    }
    for (int i = index; i < currentIndex; i++)
        arrBooks[i] = arrBooks[i + 1];

    currentIndex--;
    cout << "Da xoa sach!\n";
}
void findBookByName() {
    cin.ignore();
    cout << "Nhap ten sach can tim: ";
    string bookName;
    getline(cin, bookName);
    int cnt = 0;
    for (int i = 0; i < currentIndex; i++) {
        if (arrBooks[i].getBookName().find(bookName) != string::npos) {
            arrBooks[i].displayData();
            cnt++;
        }
    }
    cout << "Tim thay " << cnt << " ket qua.\n";
}
void findBookByPriceRange() {
    float minP, maxP;
    cout << "Nhap gia thap nhat: ";
    cin >> minP;
    cout << "Nhap gia cao nhat: ";
    cin >> maxP;

    int cnt = 0;
    for (int i = 0; i < currentIndex; i++) {
        if (arrBooks[i].getPrice() >= minP && arrBooks[i].getPrice() <= maxP) {
            arrBooks[i].displayData();
            cnt++;
        }
    }
    cout << "Tim thay " << cnt << " ket qua.\n";
}
void sortBookByPriceASC() {
    for (int i = 0; i < currentIndex - 1; i++) {
        for (int j = i + 1; j < currentIndex; j++) {
            if (arrBooks[i].getPrice() > arrBooks[j].getPrice()) {
                Book tmp = arrBooks[i];
                arrBooks[i] = arrBooks[j];
                arrBooks[j] = tmp;
            }
        }
    }
    cout << "Da sap xep theo gia tang dan!\n";
}

