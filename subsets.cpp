#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    int n = S.size();
    vector<vector<int> > result;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> level;
        for (int j = 0; j < n; ++j) {
            if ( i & (1 << j)) {
                level.push_back(S.at(j));
            }
        }

        sort(level.begin(), level.end());
        result.push_back(level);
    }

    return result;
}

