#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    string previous = "1";

    if (n == 1) {
        return previous;
    }

    int prev, count;
    for (int i = 2; i <= n; i++) {
        string current;
        prev = previous.at(0) - '0';
        count = 1;

        for (string::size_type j = 1; j < previous.size(); j++) {
            if ( prev ==  previous.at(j) - '0') {
                count++;
            } else {
                if ( count > 0) {
                    current.push_back('0' + count);
                }
                current.push_back('0' + prev);
                count = 1;
                prev = previous.at(j) - '0';
            }
        }

        // Update for the last element
        if ( count > 0) {
            current.push_back('0' + count);
        }
        current.push_back('0' + prev);
        previous = current;
    }

    return previous;
}

int main() {
    countAndSay(6);
    return 0;
}
