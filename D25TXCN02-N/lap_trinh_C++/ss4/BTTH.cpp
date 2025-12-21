#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cctype>

using namespace std;

class Student {
private:
    string studentId;
    string fullName;
    string dob;
    string gender;
    string address;
    string email;
    string phoneNumber;
    string major;
    float cgpa;
    bool status; // true: dang hoc, false: nghi hoc

public:
    Student() {
        cgpa = 0;
        status = true;
    }

    Student(string id, string name, string dob, string gender,
            string address, string email, string phone,
            string major, float cgpa, bool status) {
        this->studentId = id;
        this->fullName = name;
        this->dob = dob;
        this->gender = gender;
        this->address = address;
        this->email = email;
        this->phoneNumber = phone;
        this->major = major;
        this->cgpa = cgpa;
        this->status = status;
    }

    string getStudentId() const { return studentId; }
    string getFullName() const { return fullName; }
    string getMajor() const { return major; }
    float getCgpa() const { return cgpa; }
    bool getStatus() const { return status; }

    void setFullName(string name) { fullName = name; }
    void setMajor(string m) { major = m; }
    void setCgpa(float c) { cgpa = c; }
    void setStatus(bool s) { status = s; }

    bool isValidStudentId(string id) {
        return id.length() == 5 && id.substr(0, 2) == "SV";
    }

    bool isValidPhone(string phone) {
        if (phone.length() != 10 || phone[0] != '0') return false;
        for (int i = 0; i < phone.length(); i++)
            if (!isdigit(phone[i])) return false;
        return true;
    }

    void inputData(const vector<Student>& list) {
        while (true) {
            cout << "Ma SV (SVxxx): ";
            getline(cin, studentId);

            bool duplicate = false;
            for (int i = 0; i < list.size(); i++) {
                if (list[i].getStudentId() == studentId) {
                    duplicate = true;
                    break;
                }
            }

            if (!isValidStudentId(studentId) || duplicate)
                cout << "Ma SV khong hop le hoac bi trung.\n";
            else break;
        }

        do {
            cout << "Ho va ten: ";
            getline(cin, fullName);
        } while (fullName.length() < 10 || fullName.length() > 100);

        cout << "Ngay sinh (dd/mm/yyyy): ";
        getline(cin, dob);

        do {
            cout << "Gioi tinh (Nam/Nu): ";
            getline(cin, gender);
        } while (gender != "Nam" && gender != "Nu");

        do {
            cout << "Dia chi: ";
            getline(cin, address);
        } while (address.length() > 200);

        cout << "Email: ";
        getline(cin, email);

        do {
            cout << "So dien thoai: ";
            getline(cin, phoneNumber);
        } while (!isValidPhone(phoneNumber));

        cout << "Nganh hoc: ";
        getline(cin, major);

        do {
            cout << "CGPA (0 - 4): ";
            cin >> cgpa;
        } while (cgpa < 0 || cgpa > 4);

        int st;
        do {
            cout << "Tinh trang (1-Dang hoc, 0-Nghi hoc): ";
            cin >> st;
        } while (st != 0 && st != 1);
        status = (st == 1);

        cin.ignore();
    }

    void displayData() const {
        cout << left << setw(8) << studentId
             << setw(25) << fullName
             << setw(12) << dob
             << setw(6) << gender
             << setw(18) << major
             << setw(6) << fixed << setprecision(2) << cgpa
             << setw(12) << (status ? "Dang hoc" : "Nghi hoc")
             << endl;
    }
};

bool compareCgpa(Student a, Student b) {
    return a.getCgpa() > b.getCgpa();
}

void showMenu() {
    cout << "\n******** QUAN LY SINH VIEN ********\n";
    cout << "1. Danh sach sinh vien\n";
    cout << "2. Them moi sinh vien\n";
    cout << "3. Cap nhat thong tin sinh vien\n";
    cout << "4. Xoa sinh vien\n";
    cout << "5. Tim theo ten\n";
    cout << "6. Tim theo nganh hoc\n";
    cout << "7. Tim theo tinh trang hoc\n";
    cout << "8. Sap xep theo CGPA giam dan\n";
    cout << "9. Tinh CGPA trung binh\n";
    cout << "10. Thong ke sinh vien theo nganh\n";
    cout << "11. Thoat\n";
    cout << "Lua chon: ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            for (int i = 0; i < students.size(); i++)
                students[i].displayData();
            break;

        case 2: {
            Student s;
            s.inputData(students);
            students.push_back(s);
            break;
        }

        case 3: {
            string id;
            cout << "Nhap ma SV can cap nhat: ";
            getline(cin, id);
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getStudentId() == id) {
                    string name;
                    cout << "Ten moi: ";
                    getline(cin, name);
                    students[i].setFullName(name);
                }
            }
            break;
        }

        case 4: {
            string id;
            cout << "Nhap ma SV can xoa: ";
            getline(cin, id);
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getStudentId() == id) {
                    students.erase(students.begin() + i);
                    break;
                }
            }
            break;
        }

        case 5: {
            string key;
            cout << "Nhap ten can tim: ";
            getline(cin, key);
            for (int i = 0; i < students.size(); i++)
                if (students[i].getFullName().find(key) != string::npos)
                    students[i].displayData();
            break;
        }

        case 6: {
            string m;
            cout << "Nhap nganh: ";
            getline(cin, m);
            for (int i = 0; i < students.size(); i++)
                if (students[i].getMajor() == m)
                    students[i].displayData();
            break;
        }

        case 7: {
            bool st;
            cout << "Nhap tinh trang (1/0): ";
            cin >> st;
            for (int i = 0; i < students.size(); i++)
                if (students[i].getStatus() == st)
                    students[i].displayData();
            break;
        }

        case 8:
            sort(students.begin(), students.end(), compareCgpa);
            break;

        case 9: {
            float sum = 0;
            for (int i = 0; i < students.size(); i++)
                sum += students[i].getCgpa();
            if (!students.empty())
                cout << "CGPA trung binh: "
                     << sum / students.size() << endl;
            break;
        }

        case 10: {
            map<string, int> stat;
            for (int i = 0; i < students.size(); i++)
                stat[students[i].getMajor()]++;
            for (map<string, int>::iterator it = stat.begin();
                 it != stat.end(); ++it)
                cout << it->first << ": " << it->second << endl;
            break;
        }

        case 11:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 11);

    return 0;
}

