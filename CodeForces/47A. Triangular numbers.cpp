#include <iostream>

using namespace std;

int main() {
    int n, c = 1;
    cin >> n;
    
    for(int i = 1; c <= n; i++, c += i)
        if(c == n) {
            cout << "YES" << endl;
            return 0;
        }
    
    cout << "NO" << endl;
    
    return 0;
}
