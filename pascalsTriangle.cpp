#include <vector>
#include <iostream>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> previous, nextRow;
    previous.push_back(1);
    if (rowIndex == 0) {
        return previous;
    }

    for (int i = 0; i < rowIndex; ++i) {
        nextRow.clear();

        nextRow.push_back(1);
        for (vector<int>::size_type j = 0; j < previous.size() - 1; ++j) {
            nextRow.push_back(previous.at(j) + previous.at(j + 1));
        }
        nextRow.push_back(1);

        previous = nextRow;
    }

    return nextRow;
}

int main() {
    vector<int> result = getRow(3);

    for (vector<int>::size_type i = 0; i < result.size(); ++i) {
        cout << result.at(i) << " ";
    }
    cout << endl;
    return 0;
}
