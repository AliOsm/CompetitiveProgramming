#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    string s;
    double to;
    while(t--) {
        cin >> s;
        to = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int n = 0, tmp = i + 1;
            if(tmp < s.size() && isdigit(s[tmp]))
                while(isdigit(s[tmp]))
                    n = n * 10 + (s[tmp++] - '0');
            else n = 1;
            
            if(s[i] == 'C')
                to += n * 12.01;
            else if(s[i] == 'H')
                to += n * 1.008;
            else if(s[i] == 'O')
                to += n * 16.00;
            else if(s[i] == 'N')
                to += n * 14.01;
        }
        
        cout << fixed << setprecision(3) << to << endl;
    }
    
    return 0;
}
