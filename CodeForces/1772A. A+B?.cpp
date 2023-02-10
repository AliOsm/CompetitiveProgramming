#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t-- != 0) {
        string s;
        cin >> s;
        
        cout << (s.substr(0, 1)[0] - '0') + (s.substr(2, 1)[0] - '0') << endl; 
    }
    

    return 0;
}
