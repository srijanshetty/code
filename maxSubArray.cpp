#include<iostream>

using namespace std;

int maxSum(int A[], int n) {
    int max = A[0];

    for (int i = 1; i < n; ++i) {
        if (A[i-1] >= 0) {
            A[i] += A[i-1];
        }

        if (A[i] > max) {
            max = A[i];
        }
    }

    return max;
}

int main() {
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSum(A, 9) << endl;
    return 0;
}
