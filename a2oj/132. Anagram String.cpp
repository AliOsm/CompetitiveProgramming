#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string s1, s2;

    cin >> n;

    while (n > 0) {
        cin >> s1 >> s2;

        for (int i = s1.length() - 1; i >= 0; i--) {
            if (s2.find(s1[i]) < s2.length()) {
                s2.erase(s2.find(s1[i]), 1);
                s1.erase(s1.find(s1[i]), 1);
            }
        }

        cout << s1.length() + s2.length() << endl;
        n--;
    }
    
    return 0;
}
