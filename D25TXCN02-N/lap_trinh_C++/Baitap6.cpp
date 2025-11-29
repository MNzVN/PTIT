#include <iostream>
using namespace std;

bool laSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

bool laSoHoanHao(int x) {
    int tongUoc = 0;
    for (int i = 1; i < x; i++)
        if (x % i == 0) tongUoc += i;
    return tongUoc == x;
}

int main() {
    int luaChon, soN;

    do {
        cout << "*************** MENU ***************\n";
        cout << "1. Nhap n\n";
        cout << "2. In tu n ve 1\n";
        cout << "3. Tinh tong 1 -> n\n";
        cout << "4. In cac so le 1 -> n\n";
        cout << "5. In so nguyen to 1 -> n\n";
        cout << "6. In so hoan hao 1 -> n\n";
        cout << "7. Thoat\n";
        cout << "Chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhap n: ";
                cin >> soN;
                break;

            case 2:
                for (int i = soN; i >= 1; i--)
                    cout << i << " ";
                cout << endl;
                break;

            case 3: {
                int tong = 0;
                for (int i = 1; i <= soN; i++)
                    tong += i;
                cout << "Tong = " << tong << endl;
                break;
            }

            case 4:
                for (int i = 1; i <= soN; i++)
                    if (i % 2 != 0) cout << i << " ";
                cout << endl;
                break;

            case 5:
                for (int i = 1; i <= soN; i++)
                    if (laSoNguyenTo(i)) cout << i << " ";
                cout << endl;
                break;

            case 6:
                for (int i = 1; i <= soN; i++)
                    if (laSoHoanHao(i)) cout << i << " ";
                cout << endl;
                break;
        }

    } while (luaChon != 7);

    return 0;
}

