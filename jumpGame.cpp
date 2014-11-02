#include <iostream>
#include <vector>

using namespace std;

bool canJump(int A[], int n) {
    if ( n == 1) {
        return true;
    }

    int minjump = 1;

    for (int i = n - 2; i >= 1; --i) {
        if (A[i] >= minjump) {
            minjump = 1;
        } else {
            minjump += 1;
        }
    }

    return A[0] >= minjump;
}

int main() {
    int A[] = {2,3,1,1,4};
    cout << canJump(A, 5) << endl;

    int B[] = {3,2,1,0,4};
    cout << canJump(B, 5) << endl;

    return 0;
}
