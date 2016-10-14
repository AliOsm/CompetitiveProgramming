#include <iostream>
#include <string>

using namespace std;

const string LANGUAGE_LETTERS = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int t, words, key, j;
    string s, result = "";

    cin >> t;

    while (t--) {
        cin >> words >> key;
        cin.ignore();
        getline(cin, s);
        result.clear();

        for (int i = 0; i <= s.length() - 1; i++) {
            if (s[i] == ' ') {
                result += ' ';
                continue;
            }
                
            j = LANGUAGE_LETTERS.find(tolower(s[i]));

            if (s[i] == tolower(s[i])) {
                result += toupper(LANGUAGE_LETTERS[(j + key) % LANGUAGE_LETTERS.length()]);
            }
            else {
                result += tolower(LANGUAGE_LETTERS[(j + key) % LANGUAGE_LETTERS.length()]);
            }
        }

        cout << result << endl;
    }

    return 0;
}
