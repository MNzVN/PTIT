#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
private:
    string id;
    string name;
    int age;
    double salaryRate;
    double salary;
    string position;
    bool active;

public:
    Employee() {
        id = "";
        name = "";
        age = 0;
        salaryRate = 0;
        salary = 0;
        position = "";
        active = true;
    }

    Employee(string id, string name, int age, double salaryRate, string position, bool active) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->salaryRate = salaryRate;
        this->position = position;
        this->active = active;
        calculateSalary();
    }

    string getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    double getSalaryRate() { return salaryRate; }
    double getSalary() { return salary; }
    string getPosition() { return position; }
    bool isActive() { return active; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setSalaryRate(double rate) { this->salaryRate = rate; }
    void setPosition(string position) { this->position = position; }
    void setActive(bool active) { this->active = active; }

    void calculateSalary() {
        salary = salaryRate * 1300000;
    }


    void inputData() {
        cout << "Nhap ma nhan vien: ";
        cin >> id;
        cin.ignore();

        cout << "Nhap ten nhan vien: ";
        getline(cin, name);

        cout << "Nhap tuoi: ";
        cin >> age;

        cout << "Nhap he so luong: ";
        cin >> salaryRate;

        cin.ignore();
        cout << "Nhap chuc vu: ";
        getline(cin, position);

        cout << "Trang thai (1-dang lam, 0-da nghi): ";
        cin >> active;

        calculateSalary();
    }


    void displayData() {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(6)  << age
             << setw(10) << salaryRate
             << setw(12) << salary
             << setw(15) << position
             << (active ? "Dang lam" : "Da nghi") << endl;
    }
};

Employee employees[100];
int employeeCount = 0;

void showList() {
    if (employeeCount == 0) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(6)  << "Age"
         << setw(10) << "Rate"
         << setw(12) << "Salary"
         << setw(15) << "Position"
         << "Status" << endl;

    for (int i = 0; i < employeeCount; i++) {
        employees[i].displayData();
    }
}

void addEmployee() {
    if (employeeCount >= 100) {
        cout << "Danh sach day!\n";
        return;
    }
    cout << "Nhap thong tin nhan vien moi:\n";
    employees[employeeCount].inputData();
    employeeCount++;
    cout << "Them thanh cong!\n";
}

// 3. C?p nh?t
void updateEmployee() {
    string id;
    cout << "Nhap ma nhan vien de cap nhat: ";
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].getId() == id) {
            cout << "Cap nhat thong tin:\n";

            string name, position;
            int age;
            double rate;
            bool active;

            cin.ignore();
            cout << "Ten moi: ";
            getline(cin, name);
            cout << "Tuoi moi: ";
            cin >> age;
            cout << "He so moi: ";
            cin >> rate;

            cin.ignore();
            cout << "Chuc vu moi: ";
            getline(cin, position);
            cout << "Trang thai (1 lam, 0 nghi): ";
            cin >> active;

            employees[i].setName(name);
            employees[i].setAge(age);
            employees[i].setSalaryRate(rate);
            employees[i].setPosition(position);
            employees[i].setActive(active);
            employees[i].calculateSalary();

            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void deleteEmployee() {
    string id;
    cout << "Nhap ma nhan vien de xoa: ";
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].getId() == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            cout << "Xoa thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void searchByName() {
    string key;
    cin.ignore();
    cout << "Nhap ten de tim: ";
    getline(cin, key);

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].getName().find(key) != string::npos) {
            employees[i].displayData();
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay!\n";
}

void sortBySalary() {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = i + 1; j < employeeCount; j++) {
            if (employees[i].getSalary() < employees[j].getSalary()) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    cout << "Sap xep thanh cong!\n";
}

int main() {
    int choice;

    do {
        cout << "\n*************** EMPLOYEE MANAGEMENT ***************\n";
        cout << "1. Danh sach nhan vien\n";
        cout << "2. Them nhan vien\n";
        cout << "3. Cap nhat nhan vien\n";
        cout << "4. Xoa nhan vien\n";
        cout << "5. Tim theo ten\n";
        cout << "6. Sap xep theo luong giam dan\n";
        cout << "7. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1: showList(); break;
            case 2: addEmployee(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: searchByName(); break;
            case 6: sortBySalary(); break;
            case 7: cout << "Thoat chuong trinh...\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 7);

    return 0;
}

