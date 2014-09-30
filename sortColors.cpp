#include <iostream>

using namespace std;

void sortColors(int A[], int n) {
    int redCount = 0;
    int whiteCount = 0;
    int blueCount = 0;

    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
            ++redCount;
        }

        if (A[i] == 1) {
            ++whiteCount;
        }

        if (A[i] == 2) {
            ++blueCount;
        }
    }

    int j;
    for (j = 0; j < redCount; ++j) {
        A[j] = 0;
    }

    for (; j < whiteCount + redCount; ++j) {
        A[j] = 1;
    }

    for (; j < blueCount + redCount + whiteCount; ++j) {
        A[j] = 2;
    }
}

int main() {
    int A[] = {0, 1, 2, 0, 1, 1, 2};

    sortColors(A, 7);
    for (int j = 0; j < 7; ++j) {
        cout << A[j] << endl;
    }
}
