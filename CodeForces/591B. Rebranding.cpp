#include <iostream>
#include <string>

using namespace std;

string l = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    char a, b;
    int i1, i2;
    while(m--) {
        cin >> a >> b;
        
        i1 = l.find(a);
        i2 = l.find(b);
        
        l[i1] = b;
        l[i2] = a;
    }
    
    for(int i = 0; i < n; i++)
        cout << l[s[i]-'a'];
    cout << endl;

    return 0;
}
