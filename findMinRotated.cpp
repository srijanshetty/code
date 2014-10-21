#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &num) {
    int i = 0;
    int j = num.size() - 1;

    while (j >= i) {
        if ( num[i] <= num[j] ) {
            return num[i];
        }

        int m = i + (j - i)/2;

        if ( num[i] <= num[m] ) {
            i = m + 1;
        } else {
            j = m;
        }
    }

    return 0;
}
