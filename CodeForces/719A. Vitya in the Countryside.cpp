#include <iostream>

using namespace std;

int main() {
    int c, tmp;
    cin >> c;
    
    if(c == 1) {
        cin >> tmp;
        
        if(tmp == 15)
            cout << "DOWN" << endl;
        else if(tmp == 0)
            cout << "UP" << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    
    for(int i = 0; i < c - 2; i++) {
        cin >> tmp;
    }
    
    int a, b;
    cin >> a >> b;
    
    if(b == 15)
        cout << "DOWN" << endl;
    else if(b == 0)
        cout << "UP" << endl;
    else if(a > b)
        cout << "DOWN" << endl;
    else
        cout << "UP" << endl;

    return 0;
}
