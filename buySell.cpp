#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    int max = 0;
    vector<int>::size_type minIndex = 0;

    for (vector<int>::size_type i = 0; i < prices.size(); ++i) {
        if (prices[i] - prices[minIndex] > max) {
            max =  - prices[minIndex] + prices[i];
        }

        if (prices[i] < prices[minIndex]) {
            minIndex = i;
        }
    }

    return max;
}

int main() {
    vector<int> prices;
    prices.push_back(50);
    prices.push_back(40);
    prices.push_back(20);
    prices.push_back(10);
    prices.push_back(30);

    cout << maxProfit(prices) << endl;
    return 0;
}
