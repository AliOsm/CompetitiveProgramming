#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, tmp, c = 0;
        cin >> n;
        tmp = n;
        
        while(tmp != 0) {
            if(tmp % 10 != 0)
                if(n % (tmp % 10) == 0) c++;
            
            tmp /= 10;
        }
        
        cout << c << endl;
    }
    
    return 0;
}
