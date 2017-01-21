#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    string s;
    int res;
    for(int c = 1; t--; c++) {
        getline(cin, s);
        res = 0;
        
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'a' || s[i] == 'd' || s[i] == 'g' || s[i] == 'j' || s[i] == 'm' || s[i] == 'p' || s[i] == 't' || s[i] == 'w' || s[i] == ' ') res++;
            else if(s[i] == 'b' || s[i] == 'e' || s[i] == 'h' || s[i] == 'k' || s[i] == 'n' || s[i] == 'q' || s[i] == 'u' || s[i] == 'x') res += 2;
            else if(s[i] == 'c' || s[i] == 'f' || s[i] == 'i' || s[i] == 'l' || s[i] == 'o' || s[i] == 'r' || s[i] == 'v' || s[i] == 'y') res += 3;
            else res += 4;
        
        cout << "Case #" << c << ": " << res << endl;
    }
    
    return 0;
}
