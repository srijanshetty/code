#include<iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
    if (n == 0) {
        return n;
    }

    if (n == 1 && A[0] == elem) {
        return 0;
    }

    if (n == 1 && A[0] !=  elem) {
        return n;
    }

    int tail = n - 1;
    int i = 0;
    while (i <= tail) {
        if (A[i] == elem) {
            A[i] = A[tail];
            --tail;
        } else {
            ++i;
        }
    }

    return tail + 1;
}

int main() {
    int A[] = {1,2,3};

    int length = removeElement(A, 3, 1);
    for(int i = 0; i < length; ++i) {
        cout << A[i] << endl;
    }

    cout << endl;

    int B[] = {1,1};

    length = removeElement(B, 2, 1);
    for(int i = 0; i < length; ++i) {
        cout << B[i] << endl;
    }
    return 0;
}
