#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, s1, s2, list;

    cin >> s1 >> s2 >> list;

    s = s1 + s2;

    if (list.find(s) < list.length()) {
        cout << "Invited" << endl;
    }
    else {
        cout << "I don't have time for parties, I have thigs to do." << endl;
    }

    return 0;
}
