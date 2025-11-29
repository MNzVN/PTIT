#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    float score;

    cout << "Nhap ten: ";
    getline(cin, name);

    cout << "Nhap tuoi: ";
    cin >> age;

    cout << "Nhap diem: ";
    cin >> score;

    string rank =
        (score >= 9) ? "Xuat sac" :
        (score >= 8) ? "Gioi" :
        (score >= 7) ? "Kha" :
        (score >= 5) ? "Trung binh" : "Yeu";

    cout << "\nThong tin sinh vien:\n";
    cout << name << " - " << age << " tuoi - Diem: " << score << endl;
    cout << "Xep loai: " << rank;
}
