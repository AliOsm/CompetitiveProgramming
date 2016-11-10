#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while(true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
    	int n1, n2, d1, d2, rn, rd;
    	char op, tmp;
    	
    	cin >> n1 >> tmp >> d1 >> op >> n2 >> tmp >> d2;
    	
    	if(op == '+') {
    		rn = (n1 * d2) + (n2 * d1);
    		rd = (d1 * d2);
    	} else if(op == '-') {
    		rn = (n1 * d2) - (n2 * d1);
    		rd = (d1 * d2);
    	} else if(op == '*') {
    		rn = n1 * n2;
    		rd = d1 * d2;
    	} else if(op == '/') {
    		rn = n1 * d2;
    		rd = n2 * d1;
    	}
    	
    	cout << rn << '/' << rd << " = ";
    	
    	int GCD = abs(gcd(rn, rd));
    	
    	rn /= GCD;
    	rd /= GCD;
    	
    	cout << rn << '/' << rd;
    	cout << endl;
    }
    
    return 0;
}
