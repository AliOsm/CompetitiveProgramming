#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, r = 0;
    cin >> n;
    n--;
    string s;
    cin >> s;
    
    for(int i = 0; i < n; i++)
        if(s[i] == s[i+1]) r++;
    
    cout << r << endl;
    
    return 0;
}
