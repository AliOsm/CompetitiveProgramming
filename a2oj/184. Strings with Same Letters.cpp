#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    int i = 1, x;
    
    while (true) {
        cin >> s1 >> s2;

        x = s1.length();

        if (s1 == "END" && s2 == "END") {
            return 0;
        }

        for (int i = 0; i < x; i++) {
            if (s2.find(s1[0]) != string::npos) {
                s2.erase(s2.find(s1[0]), 1);
                s1.erase(0, 1);
            }
        }

        if(s1 == s2)
            cout << "Case " << i << ": same" << endl;
        else
            cout << "Case " << i << ": different" << endl;

        i++;
    }

    return 0;
}
