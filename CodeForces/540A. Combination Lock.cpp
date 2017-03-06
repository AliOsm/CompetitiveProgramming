#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string n1, n2;
    cin >> n1 >> n2;
    
    int res = 0, a, b, t1, t2;
    
    for(int i = 0; i < n; i++) {
        a = n1[i] - '0';
        b = n2[i] - '0';
        
        t1 = abs(a - b);
        t2 = (min(a, b) + 10) - max(a, b);
        
        res += min(t1, t2);
    }
    
    cout << res << endl;
    
    return 0;
}
