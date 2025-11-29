#include <iostream>
using namespace std;

int main() {
    int soNgay;
    const int luongNgay = 300000;

    cout << "Nhap so ngay lam viec: ";
    cin >> soNgay;

    int tongLuong = soNgay * luongNgay;

    cout << "Luong nhan vien: " << tongLuong << " VND\n";

    if (soNgay < 10)
        cout << "Canh bao: So ngay lam viec it\n";

    return 0;
}

