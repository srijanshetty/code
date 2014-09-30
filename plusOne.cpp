#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int length = digits.size();

    if (length == 0) {
        return digits;
    }

    int count = 1;
    int temp;

    for (int i = length - 1; i >= 0; -- i) {
        temp = digits[i] + count;
        digits[i] = temp % 10;
        count = temp / 10;

        if (count == 0) {
            break;
        }
    }

    if (count != 0) {
        digits.insert(digits.begin(), count);
    }

    return digits;
}

int main() {
    vector<int> A;
    A.push_back(9);
    A.push_back(9);
    A.push_back(9);

    plusOne(A);
    for (vector<int>::size_type i = 0; i < A.size(); ++i) {
        cout << A[i];
    }
    cout << endl;

    return 0;
}
