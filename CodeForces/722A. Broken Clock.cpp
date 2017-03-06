#include <iostream>

using namespace std;

int main() {
    int mode, hh, mm;
    char tmp;
    cin >> mode >> hh >> tmp >> mm;
    
    if(mode == 24) {
        while(hh > 23) {
            hh -= 10;
        }
        
        if(hh < 10)
            cout << '0';
        
        cout << hh;
    } else {
        if(hh == 0)
            hh++;
        
        while(hh > 12) {
            hh -= 10;
        }
        
        if(hh < 10)
            cout << '0';
        
        cout << hh;
    }
    
    cout << ':';
    
    while(mm > 59) {
        mm -= 10;
    }
    
    if(mm < 10)
        cout << '0';
    
    cout << mm << endl;

    return 0;
}
