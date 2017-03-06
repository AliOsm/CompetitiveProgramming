#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    if(s1.size() != s2.size())
        cout << max(s1.size(), s2.size()) << endl;
    else if(s1 == s2)
    	cout << -1 << endl;
    else
    	cout << s1.size() << endl;
    
    return 0;
}
