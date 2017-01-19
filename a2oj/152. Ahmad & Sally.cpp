#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        n = 999999 - n + 1;
        
        for(int i = n; i <= 999999; i++) {
            cout << i;
            if(i < 999999) cout << ' ';
        }
        
        cout << endl;
    }
    
    return 0;
}
