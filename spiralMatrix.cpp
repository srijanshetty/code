#include <iostream>
#include "lib/vector.cpp"

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> spiral;
    vector<int> row;

    while (!matrix.empty()) {
        row = matrix[0];
        spiral.insert(spiral.end(), row.begin(), row.end());
        matrix.erase(matrix.begin());

        if (!matrix.empty() && matrix.at(0).size() > 1) {
            int length = matrix.size();
            int position = matrix.at(0).size() - 1;
            for (int i = 0; i < length; ++i) {
                spiral.push_back(matrix[i][position]);
                matrix[i].pop_back();
            }

            row = matrix[length - 1];
            spiral.insert(spiral.end(), row.rbegin(), row.rend());
            matrix.pop_back();

            if (!matrix.empty()) {
                length = matrix.size();
                for (int i = length - 1; i > 0; --i) {
                    spiral.push_back(*(matrix[i].begin()));
                    matrix[i].erase(matrix[i].begin());
                }
            }
        }
    }

    serialize(spiral);
    return spiral;
}

#define SIZE 4
int main() {
    int n;
    cin >> n;

    vector<vector<int> > matrix;
    vector<int> level;
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            level.push_back(k++);
            cout << k - 1 << "\t";
        }
        matrix.push_back(level);
        level.clear();
        cout << endl;
    }

    spiralOrder(matrix);
    return 0;
}
