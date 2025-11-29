#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

int main() {
    const int SIZE = 5;
    Student students[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Nhap ten sinh vien " << i + 1 << ": ";
        getline(cin, students[i].name);
        cout << "Nhap tuoi: ";
        cin >> students[i].age;
        cout << "Nhap GPA: ";
        cin >> students[i].gpa;
        cin.ignore();
    }

    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ". " << students[i].name 
             << ", Tuoi: " << students[i].age 
             << ", GPA: " << students[i].gpa << endl;
    }

    int maxIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (students[i].gpa > students[maxIndex].gpa) {
            maxIndex = i;
        }
    }
    cout << "\nSinh vien co GPA cao nhat: " << students[maxIndex].name 
         << " - GPA: " << students[maxIndex].gpa << endl;

    return 0;
}

