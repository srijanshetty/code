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

int main() {
    int A[] = {1,1,2};
    cout << removeDuplicates(A, 3) << endl;
    return 0;
}
