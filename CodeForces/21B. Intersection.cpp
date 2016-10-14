#include <iostream>

using namespace std;

int main() {
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    if((a1 == 0 && b1 == 0) && (a2 == 0 && b2 == 0) && c1 != c2) {
    	cout << 0 << endl;
    	return 0;
    }
    
    if((a1 == 0 && b1 == 0 && c1 == 0) || (a2 == 0 && b2 == 0 && c2 == 0)) {
    	cout << -1 << endl;
    	return 0;
    }
    
    if((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0) && (c1 == c2)) {
    	cout << 0 << endl;
    	return 0;
    }
    
    if(a1 * b2 == b1 * a2 && b2 * c1 == c2 * b1 && c1 * a2 == c2 * a1) {
    	cout << -1 << endl;
    	return 0;
    }
    
    if(((a1 * b2) - (a2 * b1)) == 0) {
    	cout << 0 << endl;
    	return 0;
    }

    cout << 1 << endl;
    return 0;
}
