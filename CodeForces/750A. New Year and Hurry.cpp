#include <iostream>

using namespace std;

int main() {
    int n, k, c = 0;
    cin >> n >> k;
    
    int tmp = 240 - k;
    
    for(int i = 1; i <= n && tmp > 0; i++)
        if(tmp >= 5 * i) {
            tmp -= 5 * i;
            c++;
        }
    
    cout << c << endl;
    
    return 0;
}
