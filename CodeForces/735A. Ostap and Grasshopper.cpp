#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int g = s.find('G'), t = s.find('T');
    
    if(g > t) {
        for(int i = g; i >= t; i -= k) {
            if(s[i] == '#') {
                cout << "NO" << endl;
                return 0;
            } if(s[i] == 'T') {
                cout << "YES" << endl;
                return 0;
            }
        }
    } else {
        for(int i = g; i <= t; i += k) {
            if(s[i] == '#') {
                cout << "NO" << endl;
                return 0;
            } if(s[i] == 'T') {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}
