#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> &num, int i, int j, vector<vector<int> > *result) {
    if (i == j) {
        for (vector<int>::size_type i = 0; i< num.size(); ++i) {
            cout << num.at(i);
        }
        cout << endl;
        result->push_back(num);
    } else {
        for (int k = i; k <= j; k++) {
            swap(num.at(i), num.at(k));
            permutation(num, i + 1, j, result);
            swap(num.at(i), num.at(k));
        }
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    permutation(num, 0, num.size() - 1, &result);
    return result;
}

int main() {
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    permute(num);

    return 0;
}
