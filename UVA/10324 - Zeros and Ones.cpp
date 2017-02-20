#include <iostream>
#include <string>

using namespace std;

int const N = 1e6 + 1;
int cum[N];

int main() {
    string s;
    int n, l, r;
    
    for(int c = 1; cin >> s; c++) {
        cout << "Case " << c << ":" << endl;
        
        if(s[0] == '1') cum[0] = 1;
        else cum[0] = 0;
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '1') cum[i] = cum[i-1] + 1;
            else cum[i] = cum[i-1];
        }
        
        cin >> n;
        
        while(n--) {
            cin >> l >> r;
            
            if((cum[max(l, r)] - cum[min(l, r)] == max(l, r) - min(l, r) &&
                ((s[l] == '0' && s[r] != '1') || (s[l] == '1' && s[r] != '0'))) ||
                (cum[max(l, r)] - cum[min(l, r)] == 0 && s[l] != '1' && s[r] != '1'))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    
    return 0;
}
