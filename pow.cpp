#include <iostream>

using namespace std;

double pow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n == -1) {
        return 1 / x;
    }

    if (n == 1) {
        return x;
    }

    double half;
    if (n % 2 == 0) {
        half = pow(x, n/2);
        return half * half;
    }

    half = pow(x, (n-1)/2);
    return half * half * x;
}

int main() {
    cout << pow(2, 10) << endl;
    cout << pow(2, -3) << endl;
}
