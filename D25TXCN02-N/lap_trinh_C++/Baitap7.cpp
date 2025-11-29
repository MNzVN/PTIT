#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    string ma;
    string ten;
    float gia;
};

int main() {
    SanPham sp;
    int chon;

    do {
        cout << "\n---QUAN LY SAN PHAM---\n";
        cout << "1. Nhap thong tin\n";
        cout << "2. Hien thi\n";
        cout << "3. Tim theo ten\n";
        cout << "4. Cap nhat ten\n";
        cout << "5. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1:
                cout << "Nhap ma: ";
                getline(cin, sp.ma);

                cout << "Nhap ten: ";
                getline(cin, sp.ten);

                cout << "Nhap gia: ";
                cin >> sp.gia;
                cin.ignore();
                break;

            case 2:
                cout << "\nMa: " << sp.ma << endl;
                cout << "Ten: " << sp.ten << endl;
                cout << "Gia: " << sp.gia << endl;
                break;

            case 3: {
                string tenTim;
                cout << "Nhap ten can tim: ";
                getline(cin, tenTim);

                if (sp.ten == tenTim)
                    cout << "Tim thay! Ma: " << sp.ma << ", Gia: " << sp.gia << endl;
                else
                    cout << "Khong tim thay!\n";
                break;
            }

            case 4:
                cout << "Nhap ten moi: ";
                getline(cin, sp.ten);
                cout << "Cap nhat thanh cong!\n";
                break;
        }

    } while (chon != 5);

    return 0;
}

