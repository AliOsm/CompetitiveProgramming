#include <iostream>

using namespace std;

int calc(int n) {
    if(n < 10) return n;
    
    int tmp;
    
    while(n) {
        tmp += n % 10;
        n /= 10;
    }
    
    calc(tmp);
}

int main() {
    int n, tmp;
    
    while(cin >> n && n)
        cout << calc(n) << endl;
    
    return 0;
}
