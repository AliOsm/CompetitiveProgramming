#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char tmp;
    
    while(n--) {
        for(int i = 0; i < m; i++) { 
            cin >> tmp;
            if(tmp == 'C' || tmp == 'M' || tmp == 'Y') {
                cout << "#Color" << endl;
                return 0;
            }
        }
    }
   
    cout << "#Black&White" << endl;
    return 0;
}
