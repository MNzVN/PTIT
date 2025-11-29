#include <iostream>
#include <vector>
using namespace std;

double calculateSum(const vector<double> &nums) {
    double sum = 0;
    for (double n : nums) sum += n;
    return sum;
}

double calculateAverage(const vector<double> &nums) {
    if (nums.empty()) return 0;
    return calculateSum(nums) / nums.size();
}

int main() {
    vector<double> numbers;
    const int SIZE = 5;
    double temp;
    for (int i = 0; i < SIZE; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> temp;
        numbers.push_back(temp);
    }

    double sum = calculateSum(numbers);
    double avg = calculateAverage(numbers);

    cout << "Tong cua day so: " << sum << endl;
    cout << "Trung binh cua day so: " << avg << endl;

    return 0;
}

