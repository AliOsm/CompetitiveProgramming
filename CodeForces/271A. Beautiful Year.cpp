#include <iostream>
#include <memory.h>

using namespace std;

int freq[10], r;

bool distinct(int n) {
    memset(freq, 0, sizeof freq);
    r = 0;
    
    while(n) {
        freq[n % 10]++;
        n /= 10;
    }
    
    for(int i = 0; i < 10; i++)
        if(freq[i])
            r++;
    
    if(r == 4)
        return true;
    
    return false;
}

int main() {
    int n;
    cin >> n;
    n++;
    
    while(!distinct(n))
        n++;
    
    cout << n << endl;
    
    return 0;
}
