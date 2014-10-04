#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
    if (n == 0) {
        return 0;
    }

    int prev = 0;
    int length = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] == A[prev]) {
            continue;
        } else {
            ++length;
            ++prev;
            A[prev] = A[i];
        }
    }

    return length;
}

int removeDuplicates2(int A[], int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }


    int B[n];
    B[0] = A[0];
    int i = 1, k = 1, prev = 0;

    while (i < n) {
        if (A[i] == A[prev]) {
            B[k++] = A[i++];

            while (A[i] == A[prev] && i < n) {
                ++i;
            }
        } else {
            prev = i;
            B[k++] = A[i++];
        }
    }

    for (i = 0; i < k; ++i) {
        A[i] = B[i];
    }
    return k;
}

int main() {
    int A[] = {1,1,2};

    int length = removeDuplicates2(A, 3);
    for (int i = 0; i < length; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

