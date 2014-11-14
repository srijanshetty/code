#include <set>
#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string word) {
    if (word.size() == 0) {
        return 0;
    }

    map<char, int> nearestPositions;

    int end_pos, location;

    // Initliazations
    nearestPositions[word[0]] = 0;
    int current_length = 1;
    int max_length = 1;
    int start_pos = 0;

    for (int i = 1; i < (int) word.size(); ++i) {
        if (nearestPositions.count(word[i])) {
            end_pos = i;
            location = nearestPositions[word[i]];
            if (location >= start_pos && location < end_pos) {
                start_pos = location + 1;
                current_length = i - start_pos + 1;
            } else {
                current_length++;
            }
        } else {
            current_length++;
        }

        nearestPositions[word[i]] = i;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }

    return max_length;
}

int main() {
    string word;
    cin >> word;

    cout << lengthOfLongestSubstring(word) << endl;

    return 0;
}
