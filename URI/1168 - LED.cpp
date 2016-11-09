#include <iostream>
#include <string>

using namespace std;

int main() {
    int a;
    cin >> a;
    
    while(a--) {
    	string s;
    	cin >> s;
    	
    	long long c = 0;
    	
    	for(int i = 0, len = s.length(); i < len; i++)
    		if(s[i] == '1')
    			c += 2;
    		else if(s[i] == '2')
    			c += 5;
    		else if(s[i] == '3')
    			c += 5;
    		else if(s[i] == '4')
    			c += 4;
    		else if(s[i] == '5')
    			c += 5;
    		else if(s[i] == '6')
    			c += 6;
    		else if(s[i] == '7')
    			c += 3;
    		else if(s[i] == '8')
    			c += 7;
    		else if(s[i] == '9')
    			c += 6;
    		else
    			c += 6;
    	
    	cout << c << " leds" << endl;
    }
    
    return 0;
}
