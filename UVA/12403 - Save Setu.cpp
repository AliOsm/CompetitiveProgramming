#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int t = 0, tmp;
    string s;
    while(n--) {
        cin >> s;
        
        if(s == "donate") {
            cin >> tmp;
            t += tmp;
        } else cout << t << endl;
    }
    
    return 0;
}
