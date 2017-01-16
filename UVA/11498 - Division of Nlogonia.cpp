#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, a, b, x, y;
    
    while(cin >> n && n) {
        cin >> a >> b;
        
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            
            if(x < a && y > b) cout << "NO" << endl;
            else if(x > a && y > b) cout << "NE" << endl;
            else if(x > a && y < b) cout << "SE" << endl;
            else if(x < a && y < b) cout << "SO" << endl;
            else cout << "divisa" << endl;
        }
    }

	return 0;
}
