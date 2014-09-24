#include<iostream>

using namespace std;

int singleNumber(int A[], int n) {
    int sum = A[0];
    for (int i = 1; i < n; ++i) {
        sum = sum ^ A[i];
    }

    return sum;
}

int main() {
    int A[] = {1,2,3,1,2};

    cout << singleNumber(A, 5);
}
