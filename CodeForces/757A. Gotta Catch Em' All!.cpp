#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    int B, a, b, l, r, s, u;
    B = a = b = l = r = s = u = 0;
    
    for(int i = 0; i < str.size(); i++)
        switch(str[i]) {
            case 'B': B++; break;
            case 'a': a++; break;
            case 'b': b++; break;
            case 'l': l++; break;
            case 'r': r++; break;
            case 's': s++; break;
            case 'u': u++; break;
        }
    a /= 2;
    u /= 2;
    
    cout << min(B, min(a, min(b, min(l, min(r, min(s, u)))))) << endl;
    
    return 0;
}
