#include <iostream>
using namespace std;

int main() {
    int soLuong;
    float giaBan;

    cout << "Nhap so luong san pham: ";
    cin >> soLuong;

    cout << "Nhap gia ban 1 san pham: ";
    cin >> giaBan;

    float tongTien = soLuong * giaBan;
    float tyLeGiam = 0;

    if (soLuong >= 7)
        tyLeGiam = 0.30;
    else if (soLuong >= 5)
        tyLeGiam = 0.20;
    else if (soLuong >= 3)
        tyLeGiam = 0.10;

    float tienSauGiam = tongTien - tongTien * tyLeGiam;

    cout << "Tong tien: " << tongTien << endl;
    cout << "Giam gia: " << tyLeGiam * 100 << "%\n";
    cout << "Thanh toan: " << tienSauGiam << endl;

    return 0;
}

