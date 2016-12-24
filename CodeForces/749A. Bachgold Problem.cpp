#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n % 2 == 1) {
        n /= 2;
        n--;
        cout << n + 1 << endl << 3 << ' ';
    } else {
        n /= 2;
        cout << n << endl;
    }
    
    for(int i = 0; i < n; i++) cout << 2 << ' ';
    cout << endl;
}
