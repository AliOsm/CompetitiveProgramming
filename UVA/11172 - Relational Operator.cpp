#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int a, b;
    while(t--) {
        cin >> a >> b;
        
        if(a > b) cout << '>' << endl;
        else if(a < b) cout << '<' << endl;
        else cout << '=' << endl;
    }
    
    return 0;
}
