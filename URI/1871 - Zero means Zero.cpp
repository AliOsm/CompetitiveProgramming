#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, b;
    
    while(cin >> a >> b && a && b) {
    	stringstream ss;
    	ss << a + b;
    	string s;
    	ss >> s;
    	
    	for(int i = 0, len = s.length(); i < len; i++)
    		if(s[i] != '0')
    			cout << s[i];
    	cout << endl;
    }
    
    return 0;
}
