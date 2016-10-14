#include <iostream>
#include <string>

using namespace std;

const string LANGUAGE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    int t;
    cin >> t;

    string msg, table, res;

    for (int j = 1; j <= t; j++) {
        cin.ignore();
        getline(cin, msg);
        cin >> table;
        res = "";

        for (int i = 0; i < msg.length(); i++) {
            if (msg[i] == ' ') {
                res += ' ';
                continue;
            }

            res += table[LANGUAGE_LETTERS.find(msg[i])];
        }

        cout << j << ' ' << res << endl;
    }

    return 0;
}
