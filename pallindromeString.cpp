#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool isPallindrome(string s) {
    int length = s.length();
    if (length == 0) {
        return true;
    }

    int i = 0;
    int j = length - 1;

    while (i <= j) {
        if (!isalnum(s[i])) {
            ++i;
            continue;
        }

        if (!isalnum(s[j])) {
            --j;
            continue;
        }

        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        ++i;
        --j;
    }

    return true;
}

int main() {
    cout << isPallindrome("srijan") << endl;
    cout << isPallindrome("race a car") << endl;
    cout << isPallindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
