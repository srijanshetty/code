#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    string::reverse_iterator first = a.rbegin();
    string::reverse_iterator second = b.rbegin();
    string result;

    int sum = 0;
    int carry = 0;
    int digit = 0;
    while (first != a.rend() && second != b.rend()) {
        digit = (*first - '0') + (*second -'0') + carry;
        sum = digit % 2;
        carry = digit / 2;
        result.push_back(sum + '0');
        first++;
        second++;
    }

    if (first != a.rend()) {
        while (first != a.rend()) {
            if (carry != 0) {
                digit = (*first -'0') + carry;
                sum = digit % 2;
                carry = digit / 2;
                result.push_back(sum + '0');
            } else {
                result.push_back(*first);
            }
            first++;
        }
    }

    if (second != b.rend()) {
        while (second != b.rend()) {
            if (carry != 0) {
                digit = (*second-'0') + carry;
                sum = digit % 2;
                carry = digit / 2;
                result.push_back( sum + '0');
            } else {
                result.push_back(*second);
            }
            second++;
        }
    }

    if (first == a.rend() && second == b.rend() && carry != 0) {
        result.push_back(carry + '0');
    }


    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << addBinary("101", "010") << endl;
    cout << addBinary("1101", "1") << endl;
    cout << addBinary("1", "1101") << endl;
    return 0;
}
