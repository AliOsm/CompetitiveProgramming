#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, r, tmp;
    string s;
    vector<int> ins;
    while(t--) {
        cin >> n;
        r = 0;
        ins.clear();
        
        while(n--) {
            cin >> s;
            
            switch(s[0]) {
                case 'R':
                    ins.push_back(1);
                    r++;
                    break;
                case 'L':
                    ins.push_back(-1);
                    r--;
                    break;
                default:
                    cin >> s >> tmp;
                    ins.push_back(ins[tmp-1]);
                    r += ins.back();
            }
        }
        
        cout << r << endl;
    }
    
    return 0;
}
