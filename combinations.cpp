#include <iostream>
#include <vector>

using namespace std;

void computeCombination(int current, int elements, int n, int k, vector<int> &data, vector<vector<int> > &result) {
    if (elements == k) {
        // for (vector<int>::iterator i = data.begin(); i != data.end(); i++) {
        //     cout << *i;
        // }
        // cout << endl;
        result.push_back(data);
    } else {
        if (current > n) {
            return;
        }

        // We include the element
        data.push_back(current);
        computeCombination(current + 1, elements + 1, n, k, data, result);

        // Or we don't include the element
        data.pop_back();
        computeCombination(current + 1, elements, n, k, data, result);
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    vector<int> data;
    computeCombination(1, 0 , n, k, data, result);
    return result;
}

int main() {
    combine(2, 1);
    return 0;
}
