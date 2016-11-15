#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> pre_calc;

int main() {
    for(char i = 'a'; i <= 'z'; i++) {
    	int x = 0, y = 25;
    	
    	for(char j = 'a'; j <= 'z'; j++) {
    		string s = "";
    		s += i;
    		s += j;
    		if(i <= j) pre_calc[s] = x++;
    		else pre_calc[s] = (j - 'a') + ('z' - i) + 1;
    	}
    }
    
    int t;
    cin >> t;
    
    while(t--) {
    	string s1, s2;
    	cin >> s1 >> s2;
    	
    	int c = 0;
    	for(int i = 0, len = s1.length(); i < len; i++) {
    		string s = "";
    		s += s1[i];
    		s += s2[i];
    		c += pre_calc[s];
    	}
    	
    	cout << c << endl;
    }
    
    return 0;
}
