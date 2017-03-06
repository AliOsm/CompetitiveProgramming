#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++) 
        if(s[i] == '.') cout << '0';
        else if(i+1 < s.size() && s[i] == '-' && s[i+1] == '.') {
            cout << '1';
            i++;
        } else if(i+1 < s.size() && s[i] == '-' && s[i+1] == '-') {
            cout << '2';
            i++;
        }
    
    cout << endl;
    return 0;
}
