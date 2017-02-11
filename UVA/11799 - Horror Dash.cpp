#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, mx, tmp;
    for(int i = 1; t--; i++) {
        mx = 0;
        
        cin >> n;
        
        while(n--) {
            cin >> tmp;
            if(tmp > mx) mx = tmp;
        }
        
        cout << "Case " << i << ": " << mx << endl;
    }
    
    return 0;
}
