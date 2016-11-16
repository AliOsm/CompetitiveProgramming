#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	m.clear();
    	
    	int n;
    	cin >> n;
    	
    	while(n--) {
	    	string s;
	    	cin >> s;
	    	
	    	m[s]++;
    	}
    	
    	if(m.size() > 1)
    		cout << "ingles" << endl;
    	else if(m.size() == 1)
    		cout << m.begin()->first << endl;
    }
    
    return 0;
}
