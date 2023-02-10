#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t-- != 0) {
        int n, k;
        cin >> k >> n;

        int elements = 0, last = 0;
        for(int i = 1, j = 1;; i += j,  ++j) {
            if(elements == k || k - (elements + 1) > n - i) {
                break;
            }

            cout << i << ' ';
            last = i;
            ++elements;
        }
        
        while(elements < k) {
            cout << ++last << ' ';
            ++elements;
        }
        
        puts("");
        
    }

    return 0;
}
