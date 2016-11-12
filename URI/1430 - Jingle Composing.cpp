#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, double> m;

int main() {
	m['W'] = 1;
	m['H'] = 0.5;
	m['Q'] = 0.25;
	m['E'] = 0.125;
	m['S'] = 0.0625;
	m['T'] = 0.03125;
	m['X'] = 0.015625;
	
    while(true) {
    	string s;
    	cin >> s;
    	
    	if(s == "*") break;
    	
    	double cur_t = 0;
    	int c = 0;
    	
    	for(int i = 1, len = s.length(); i < len; i++) {
    		if(s[i] == '/') {
    			if(cur_t == 1) c++;
    			cur_t = 0;
    		} else
    			cur_t += m[s[i]];
    	}
    	
    	cout << c << endl;
    }
    
    return 0;
}
