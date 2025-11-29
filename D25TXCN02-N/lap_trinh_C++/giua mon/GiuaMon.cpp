#include <iostream>
#include <string>
using namespace std;

struct Volume {
    string label;
    string writer;
    int publishYear;
    double cost;
    int stock;
};

Volume shelf[100]; 
int totalItems = 0;

void insertItem() {
    if (totalItems >= 100) {
        cout << "Khong the them, ke sach da day!\n";
        return;
    }

    cin.ignore();
    cout << "Nhap ten sach: ";
    getline(cin, shelf[totalItems].label);
    cout << "Nhap ten tac gia: ";
    getline(cin, shelf[totalItems].writer);
    cout << "Nhap nam xuat ban: ";
    cin >> shelf[totalItems].publishYear;
    cout << "Nhap gia ban: ";
    cin >> shelf[totalItems].cost;
    cout << "Nhap so luong: ";
    cin >> shelf[totalItems].stock;

    totalItems++;
    cout << "=> Da them vao ke sach!\n";
}

void displayAll() {
    if (totalItems == 0) {
        cout << "Chua co cuon sach nao!\n";
        return;
    }

    cout << "\n===== DANH SACH HIEN CO =====\n";
    for (int p = 0; p < totalItems; p++) {
        cout << p + 1 << ". "
             << shelf[p].label << " | "
             << shelf[p].writer << " | "
             << shelf[p].publishYear << " | "
             << shelf[p].cost << " | SL: "
             << shelf[p].stock << "\n";
    }
}

void searchByTitle() {
    cin.ignore();
    string keyword;
    cout << "Nhap ten sach can tim: ";
    getline(cin, keyword);

    bool exist = false;
    for (int x = 0; x < totalItems; x++) {
        if (shelf[x].label == keyword) {
            cout << "Tim thay: " << shelf[x].label
                 << " - " << shelf[x].writer << "\n";
            exist = true;
        }
    }

    if (!exist) cout << "Khong co sach phu hop!\n";
}

void searchByWriter() {
    cin.ignore();
    string key;
    cout << "Nhap ten tac gia: ";
    getline(cin, key);

    bool exist = false;
    for (int x = 0; x < totalItems; x++) {
        if (shelf[x].writer == key) {
            cout << "Sach: " << shelf[x].label << "\n";
            exist = true;
        }
    }

    if (!exist) cout << "Khong tim thay tac gia nay!\n";
}

void modifyStock() {
    cin.ignore();
    string name;
    cout << "Nhap ten sach can cap nhat: ";
    getline(cin, name);

    for (int k = 0; k < totalItems; k++) {
        if (shelf[k].label == name) {
            cout << "Nhap so luong moi: ";
            cin >> shelf[k].stock;
            cout << "=> Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay sach!\n";
}

void removeItem() {
    cin.ignore();
    string target;
    cout << "Nhap ten sach can xoa: ";
    getline(cin, target);

    for (int z = 0; z < totalItems; z++) {
        if (shelf[z].label == target) {

            for (int t = z; t < totalItems - 1; t++) {
                shelf[t] = shelf[t + 1];
            }

            totalItems--;
            cout << "=> Da xoa sach!\n";
            return;
        }
    }

    cout << "Khong tim thay sach de xoa!\n";
}

void calculateValue() {
    double money = 0;
    for (int i = 0; i < totalItems; i++) {
        money += shelf[i].cost * shelf[i].stock;
    }
    cout << "Tong gia tri thu vien: " << money << "\n";
}

void arrangeByYear() {
    for (int a = 0; a < totalItems - 1; a++) {
        for (int b = a + 1; b < totalItems; b++) {
            if (shelf[a].publishYear > shelf[b].publishYear) {
                swap(shelf[a], shelf[b]);
            }
        }
    }
    cout << "=> Da sap xep theo nam xuat ban!\n";
}

int main() {
    int option;

    do {
        cout << "\n********** QUAN LY THU VIEN **********\n";
        cout << "1. Them sach\n";
        cout << "2. In danh sach sach\n";
        cout << "3. Tim sach theo ten\n";
        cout << "4. Tim sach theo tac gia\n";
        cout << "5. Cap nhat so luong sach\n";
        cout << "6. Xoa sach\n";
        cout << "7. Tong gia tri thu vien\n";
        cout << "8. Sap xep sach theo nam\n";
        cout << "9. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> option;

        switch (option) {
            case 1: insertItem(); break;
            case 2: displayAll(); break;
            case 3: searchByTitle(); break;
            case 4: searchByWriter(); break;
            case 5: modifyStock(); break;
            case 6: removeItem(); break;
            case 7: calculateValue(); break;
            case 8: arrangeByYear(); break;
            case 9:
                cout << "Thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (option != 9);

    return 0;
}



























//TranHieuNghia
