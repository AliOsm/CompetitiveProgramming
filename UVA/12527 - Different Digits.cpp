#include <iostream>

using namespace std;

bool can(int n) {
    int freq[10] = {0};
    
    while(n) {
        freq[n % 10]++;
        n /= 10;
    }
    
    for(int i = 0; i < 10; i++)
        if(freq[i] >= 2)
            return false;
    
    return true;
}

int main() {
    int n, m, c;
    
    while(cin >> n >> m) {
        c = 0;
        
        for(int i = n; i <= m; i++)
            if(can(i)) c++;
        
        cout << c << endl;
    }
    
    return 0;
}
