#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, string> mp;
    string s;
    
    while(getline(cin, s) && s != "")
        mp[s.substr(s.find(' ') + 1)] = s.substr(0, s.find(' '));
    
    while(cin >> s)
        if(mp.count(s)) cout << mp[s] << endl;
        else cout << "eh" << endl;
	
	return 0;
}
