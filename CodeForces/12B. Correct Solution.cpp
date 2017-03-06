#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    sort(a.begin(), a.end());
    
    if(a[0] == '0')
        for(int i = 0; i < a.size(); i++)
            if(a[i] != '0') {
                a[0] = a[i];
                a[i] = '0';
                break;
            }
    
    if(a == b) cout << "OK" << endl;
    else cout << "WRONG_ANSWER" << endl;
    
    return 0;
}
