#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<int, string> mp;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	mp.clear();
    	
    	int n, m;
    	cin >> n >> m;
    	
    	for(int i = 0; i < n; i++) {
    		stringstream ss;
    		ss << i;
    		string s;
    		ss >> s;
    		mp[i] = s + " -> ";
    	}
    	
    	for(int i = 0; i < m; i++) {
    		int tmp;
    		cin >> tmp;
    		
    		stringstream ss;
    		ss << tmp;
    		string s;
    		ss >> s;
    		
    		mp[tmp % n] += s + " -> ";
    	}
    	
    	for(map<int, string>::iterator it = mp.begin(); it != mp.end(); it++)
    		cout << it->second << '\\' << endl;
    	
    	if(t) cout << endl;
    }
    
    return 0;
}
