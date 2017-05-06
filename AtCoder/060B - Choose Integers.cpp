#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    	
    int tmp;
    for(int i = 2; i < 10000; i++) {
        tmp = a * i;
        if((a + tmp) % b == c % b) {
            cout << "YES" << endl;
            return 0;
	}
    }
    	
    cout << "NO" << endl;
     
    return 0;
}
