#include<iostream>

using namespace std;

void merge(int A[], int m, int B[], int n) {
    int C[m];

    for (int i = 0; i < m; ++i) {
        C[i] = A[i];
    }


    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (C[i] < B[j]) {
            A[k++] = C[i++];
        } else if (C[i] > B[j]) {
            A[k++] = B[j++];
        } else {
            A[k++] = C[i++];
            A[k++] = B[j++];
        }
    }

    if (i < m) {
        while (i < m) {
            A[k++] = C[i++];
        }
    }

    if (j < n) {
        while (j < n) {
            A[k++] = B[j++];
        }
    }
}

int main() {
    int A[10] = {1,3,5,7};
    int B[1];

    merge(A, 4, B, 0);
    for (int i = 0; i < 8; ++i) {
        cout << A[i] << endl;
    }

    return 0;
}
