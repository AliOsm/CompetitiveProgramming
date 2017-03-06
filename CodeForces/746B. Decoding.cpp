#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, nTmp, res;
    string s, sTmp;
    cin >> n >> s;
    
    if(n % 2 == 0) {
        nTmp = n - 1;
        res = 0;
    } else {
        nTmp = n;
        res = 1;
    }
    
    sTmp = s[0];
    
    for(int i = 1; i < nTmp; i++)
        if(i % 2 == res) sTmp = s[i] + sTmp;
        else sTmp += s[i];
    
    if(n % 2 == 0)
        sTmp += s[n-1];
    
    cout << sTmp << endl;
    
    return 0;
}
