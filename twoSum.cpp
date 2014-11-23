#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    map <int, int> locations;

    for (vector<int>::size_type i = 0; i < numbers.size(); ++i) {
        locations[numbers[i]] = i;
    }

    vector<int> results;
    int toFind;
    for (vector<int>::size_type i = 0; i < numbers.size(); ++i) {
        toFind = target - numbers[i];
        if (locations.count(toFind) && locations[toFind] != (int)i) {
            results.push_back((int)i + 1);
            results.push_back(locations[toFind] + 1);
        }
    }

    return results;
}

int main() {
    int A[] = {3,2,4};
    vector<int> numbers(A, A + 3);
    vector<int> results = twoSum(numbers, 6);

    cout << results[0] << " " << results[1] << endl;
    return 0;
}
