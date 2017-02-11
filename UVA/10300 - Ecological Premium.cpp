#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, a, b, c, res;
    while(t--) {
        res = 0;
        
        cin >> n;
        
        while(n--) {
            cin >> a >> b >> c;
            res += a * c;
        }
        
        cout << res << endl;
    }
    
    return 0;
}
