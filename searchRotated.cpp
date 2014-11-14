#include <iostream>

using namespace std;
int binarySearch(int A[], int first, int last, int target) {
    while (first <= last) {
        int middle = (first + last)/2;
        if (target == A[middle]) {
            return middle;
        } else if (target > A[middle]) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }

    return -1;
}

int search(int A[], int n, int target) {
    int first = 0;
    int last = n - 1;

    while (first <= last) {
        int middle = (first + last)/2;

        if (A[first] <= A[last]) {
            return binarySearch(A, first, last, target);
        } else {
            if (A[first] <= A[middle]) {
                if (target >= A[first] && target <= A[middle]) {
                    return binarySearch(A, first, middle, target);
                } else {
                    first = middle + 1;
                }
            } else {
                if (target >= A[middle] && target <= A[last]) {
                    return binarySearch(A, middle, last, target);
                } else {
                    last = middle - 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    int A[] = {3,1};
    cout << search(A, 2, 1) << endl;
    cout << search(A, 2, 2) << endl;
}
