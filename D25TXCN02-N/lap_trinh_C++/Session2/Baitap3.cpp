#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    vector<Contact> contacts;
    const int SIZE = 10;

    for (int i = 0; i < SIZE; i++) {
        Contact c;
        cout << "Nhap ten lien lac " << i + 1 << ": ";
        getline(cin, c.name);
        cout << "Nhap so dien thoai: ";
        getline(cin, c.phone);
        contacts.push_back(c);
    }

    cout << "\nDanh ba:\n";
    for (auto &c : contacts) {
        cout << c.name << " - " << c.phone << endl;
    }

    string keyword;
    cout << "\nNhap tu khoa de tim kiem: ";
    getline(cin, keyword);

    cout << "Ket qua tim kiem:\n";
    for (auto &c : contacts) {
        if (c.name.find(keyword) != string::npos) {
            cout << c.name << " - " << c.phone << endl;
        }
    }

    return 0;
}

