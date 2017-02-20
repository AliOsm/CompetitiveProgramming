#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> mp;

int main() {
    int n;
    cin >> n;
    
    string s;
    
    cin.ignore();
    while(n--) {
        getline(cin, s);
        mp[s.substr(0, s.find(' '))]++;
    }
    
    map<string, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
        cout << it->first << ' ' << it->second << endl;
    
    return 0;
}
