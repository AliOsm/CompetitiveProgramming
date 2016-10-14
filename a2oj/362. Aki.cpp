#include <iostream>
#include <string>

using namespace std;

string reverse(string s1) {
    string s2 = "";

    for (int i = s1.length() - 1; i >= 0; i--) {
        s2 += s1[i];
    }

    return s2;
}

int main() {
    string s1, s2;

    cin >> s1;

    s2 = reverse(s1);

    for (int i = 0; i <= s1.length() - 1; i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            cout << "Not Palindrome" << endl;
            return 0;
        }
    }

    cout << "Palindrome" << endl;

    return 0;
}
