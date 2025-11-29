#include <iostream>
using namespace std;

int main() {
    int soKwh;
    long tienPhaiTra = 0;

    cout << "Nhap so kWh su dung trong thang: ";
    cin >> soKwh;

    if (soKwh < 100) {
        tienPhaiTra = soKwh * 1500;
    }
    else if (soKwh <= 200) {
        tienPhaiTra = soKwh * 2000;
    }
    else {
        tienPhaiTra = soKwh * 2500;
    }

    cout << "Tien dien phai thanh toan: " << tienPhaiTra << " VND" << endl;

    return 0;
}

