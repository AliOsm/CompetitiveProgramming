#include <iostream>
#include <string>
#include <vector>

using namespace std;

string capitalize(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }

    return s;
}

string getName(string s) {
    return capitalize(s.substr(0, s.find(' ', s.find(' ') + 1)));
}

int main() {
    int n, u;
    string oldName, newName;
    bool valid = false;

    cin >> n;
    vector<string> oldList(n);

    cin.ignore();

    for (int i = 0; i < n; i++) {
        
        getline(cin, oldList[i]);
    }

    cin >> u;
    vector<string> newList(u);

    cin.ignore();

    for (int i = 0; i < u; i++) {
        getline(cin, newList[i]);
    }

    vector<string> result;

    for (int i = 0; i < n; i++) {
        valid = false;
        oldName = getName(oldList[i]);

        for (int j = 0; j < u; j++) {
            newName = getName(newList[j]);

            if (oldName == newName) {
                result.push_back(newList[j]);
                valid = true;
            }
        }

        if (!valid)
            result.push_back(oldList[i]);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
