#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n >> t >> s;
    
    while(t--)
        for(int i = n - 1; i >= 0; i--)
            if(s[i] == 'G' && i-1 >= 0 && s[i-1] == 'B') {
                s[i] = 'B';
                s[i-1] = 'G';
                i--;
            }
    
    cout << s << endl;

    return 0;
}
