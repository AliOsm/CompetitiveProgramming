#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const string LANGUAGE_LETTERS = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int key = 13, j;
    string s, result = "";

    while (getline(cin, s)) {
        result.clear();

        for (int i = 0; i <= s.length() - 1; i++)
            if (!isalpha(s[i]))
                result += s[i];
            else {
	            j = LANGUAGE_LETTERS.find(tolower(s[i]));

	            if (s[i] == tolower(s[i]))
	                result += tolower(LANGUAGE_LETTERS[(j + key) % LANGUAGE_LETTERS.length()]);
	            else
	                result += toupper(LANGUAGE_LETTERS[(j + key) % LANGUAGE_LETTERS.length()]);
	          }

        cout << result << endl;
    }

    return 0;
}
