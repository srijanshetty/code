#include<iostream>

using namespace std;

int climbStairs(int n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else if (n==2) {
        return 2;
    }

    int a = 1;
    int b = 2;
    int c;

    for (int i=3; i<n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs(n);
    return 0;
}
