#include<iostream>

using namespace std;

bool isPallindrome(int x) {
    if (x < 0) {
        return false;
    }

    if (x == 0 || x / 10 == 0) {
        return true;
    }

    int copy = x;
    int reverse, digit;
    while (copy > 0) {
        digit = copy % 10;
        reverse = reverse * 10 + digit;
        copy = copy / 10;
    }

    if (x == reverse) {
        return true;
    }

    return false;
}

int main() {
    cout << isPallindrome(100) << endl;
    cout << isPallindrome(101) << endl;
    cout << isPallindrome(1) << endl;

    return 0;
}
