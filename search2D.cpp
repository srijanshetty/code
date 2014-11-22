#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    for (vector<vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) {
        vector<int> current = *it;
        if (target >= current.front() && target <= current.back()) {
            return binary_search(current.begin(), current.end(), target);
        }
    }

    return false;
}

int main() {

    return 0;
}
