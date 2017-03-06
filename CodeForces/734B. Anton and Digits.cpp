#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int cc = 0;
    
    while(a && c && d) {
    	cc += 256;
    	a--;
    	c--;
    	d--;
    }
    
    while(a && b) {
    	cc += 32;
    	a--;
    	b--;
    }
    
    cout << cc << endl;
    
    return 0;
}
