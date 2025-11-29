#include <iostream>
#include <map>
#include <string>
using namespace std;

void addProduct(map<string, string> &products, const string &id, const string &name) {
    products[id] = name;
}

string getProductName(const map<string, string> &products, const string &id) {
    if (products.find(id) != products.end()) return products.at(id);
    else return "Khong tim thay san pham!";
}

int main() {
    map<string, string> products;
    const int SIZE = 5;
    string id, name;

    for (int i = 0; i < SIZE; i++) {
        cout << "Nhap ma san pham: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ten san pham: ";
        getline(cin, name);
        addProduct(products, id, name);
    }

    cout << "\nNhap ma san pham can tim: ";
    cin >> id;
    cout << "Ten san pham: " << getProductName(products, id) << endl;

    return 0;
}

