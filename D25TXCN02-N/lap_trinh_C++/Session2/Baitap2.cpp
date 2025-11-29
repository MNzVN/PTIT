#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, double> studentScores;
    string id;
    double score;
    const int SIZE = 5;

    for (int i = 0; i < SIZE; i++) {
        cout << "Nhap ma hoc sinh: ";
        cin >> id;
        cout << "Nhap diem: ";
        cin >> score;
        studentScores[id] = score;
    }

    double sum = 0;
    for (auto &entry : studentScores) {
        sum += entry.second;
    }
    double average = sum / SIZE;
    cout << "\nDiem trung binh cua tat ca hoc sinh: " << average << endl;

    string bestId;
    double maxScore = -1;
    for (auto &entry : studentScores) {
        if (entry.second > maxScore) {
            maxScore = entry.second;
            bestId = entry.first;
        }
    }
    cout << "Hoc sinh co diem cao nhat: " << bestId 
         << " - Diem: " << maxScore << endl;

    return 0;
}

