#include <iostream>
using namespace std;

int main() {
    int gioMoiTuan;

    cout << "Nhap so gio lam viec moi tuan: ";
    cin >> gioMoiTuan;

    int gioThang = gioMoiTuan * 4;

    cout << "Tong gio lam viec trong thang: " << gioThang << endl;

    if (gioThang < 160)
        cout << "So gio lam viec it\n";
    else if (gioThang <= 200)
        cout << "Nhan vien lam viec du gio\n";
    else
        cout << "Nhan vien lam viec nhieu gio\n";

    return 0;
}

