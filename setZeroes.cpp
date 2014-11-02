#include <iostream>
#include <set>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
    set<int> rows;
    set<int> columns;

    int noRows = matrix.size();
    int noColumns = matrix.at(0).size();

    for (int i = 0; i < noRows; ++i) {
        for (int j = 0; j < noColumns; ++j) {
            if (matrix[i][j] == 0) {
                if (!rows.count(i)) {
                    rows.insert(i);
                }

                if (!columns.count(j)) {
                    columns.insert(j);
                }
            }
        }
    }

    for (set<int>::iterator i = rows.begin(); i != rows.end(); ++i) {
        for (int k = 0; k < noColumns; ++k) {
            matrix[*i][k] = 0;
        }
    }

    for (set<int>::iterator i = columns.begin(); i != columns.end(); ++i) {
        for (int k = 0; k < noRows; ++k) {
            matrix[k][*i] = 0;
        }
    }
}
