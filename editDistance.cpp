#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            if (word1 == "" && word2 == "") {
                return 0;
            }

            if (word1 == "") {
                return word2.size();
            }

            if (word2 == "") {
                return word1.size();
            }

            vector<int> previous(word2.size() + 1, 0);
            vector<int> current(word2.size() + 1, 0);

            int word1_length = word1.size();
            int word2_length = word2.size();

            for (int j = 1; j <= word2_length; ++j) {
                previous[j] = j;
            }

            for (int i = 0; i <= word1_length; ++i){
                for (int j = 0; j <=word2_length; ++j) {
                    if (word1[i] == word2[j]) {
                        current[j] = previous[j-1];
                    } else {
                        current[j]  = previous[j-1] + 1;
                    }

                    current[j]  = min(current[j] , current[j-1] + 1);
                    current[j]  = min(current[j] , previous[j] + 1);
                }

                previous = current;
            }

            return current[word2_length];
        }
};

int main() {
    Solution sol = Solution();
    string first, second;
    cin >> first >> second;
    cout << sol.minDistance(first, second) << endl;
    return 0;
}
