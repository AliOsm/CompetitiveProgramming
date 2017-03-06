#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    for(int i = 0, len = s.length() - 2; i < len; i++) {
        if(s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
            int j = i + 3;
            while(s[j] == 'g' && s[j+1] == 'o')
                j += 2;
            
            s = s.substr(0, i) + "***" + s.substr(j);
            len = s.length() - 2;
        }
    }
    
    cout << s << endl;
}
