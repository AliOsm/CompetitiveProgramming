#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int n, m, to;
    map<char, int> mp;
    char c;
    string s;
    while(t--) {
      mp.clear();
      to = 0;
        
	    cin >> n;
	    
	    while(n--) {
	       cin >> c;
	       cin >> mp[c];
	    }
	    
	    cin >> m;
	    
	    cin.ignore();
	    while(m--) {
	        getline(cin, s);
	        
	        for(int i = 0; i < s.length(); i++)
	            to += mp[s[i]];
	    }
	    
	    cout << fixed << setprecision(2) << to / 100.0 << '$' << endl;
    }
	
	return 0;
}
