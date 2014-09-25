#include<iostream>
using namespace std;

int reverse(int x) {
    int copy, prefix = 1;
    if (x < 0) {
        copy = -x;
        prefix = -1;
    } else {
        copy = x;
    }

    int digit, reverse = 0;
    while (copy > 0) {
        digit = copy %10;
        reverse = reverse * 10 + digit;
        copy = copy / 10;
    }

    return reverse * prefix;
}

int main() {
    cout << reverse(100) << endl;
    cout << reverse(101) << endl;
    cout << reverse(-101) << endl;
    cout << reverse(1000000003) << endl;
    return 0;
}
