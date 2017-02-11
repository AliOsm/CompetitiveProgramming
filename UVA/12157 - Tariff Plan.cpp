#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, r1, r2, tmp;
    for(int i = 1; t--; i++) {
        r1 = r2 = 0;
        
        cin >> n;
        
        while(n--) {
            cin >> tmp;
            
            r1 += (tmp / 30) * 10 + 10;
            r2 += (tmp / 60) * 15 + 15;
        }
        
        cout << "Case " << i << ": ";
        
        if(r1 == r2)
            cout << "Mile Juice " << r1 << endl;
        else if(r1 < r2)
            cout << "Mile " << r1 << endl;
        else
            cout << "Juice " << r2 << endl;
    }
    
    return 0;
}
