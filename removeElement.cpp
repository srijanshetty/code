#include<iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
    int length = n-1;
    for(int i = 0; i <= length; ++i) {
        if(A[i] == elem) {
            while (A[length] != elem) {
                length--;
            }
            A[i] = A[length--];
        }
    }

    return length + 1;
}

int main() {
    int A[] = {1,2,3,4,1,6,3,4};

    int length = removeElement(A, 8, 1);
    for(int i = 0; i < length; ++i) {
        cout << A[i] << endl;
    }

    return 0;
}
