#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
    if (n == 0) {
        return 0;
    }

    int first = 0;
    int last = n - 1;
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (A[middle] == target) {
            return middle;
        } else if (target < A[middle]) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }

    if (first >= n) {
        first = n - 1;
    }

    if (target < A[first]) {
        return first;
    } else {
        return first + 1;
    }

    return -1;
}

int main() {
    int A[] = {1,3,5,7,9};
    cout << searchInsert(A, 5, 6) << endl;
    return 0;
}
