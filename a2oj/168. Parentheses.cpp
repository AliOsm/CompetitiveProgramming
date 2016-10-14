#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isOk(string s) {
    short tmp = 0;

    for (short i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            tmp++;
        else
            tmp--;

        if (tmp < 0)
            return false;
    }

    return true;
}

int main() {
    short t;
    cin >> t;

    string s = "";

    for (short i = 0; i < t; i++) s += "(";
    for (short i = 0; i < t; i++) s += ")";

    cout << s << endl;

    while (next_permutation(s.begin(), s.end()))
        if (isOk(s))
            cout << s << endl;

    return 0;
}
