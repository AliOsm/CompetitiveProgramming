#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    
    for(int i = 1; cin >> s && s != "*"; i++) {
        cout << "Case " << i << ": ";
        
        if(s == "Hajj") cout << "Hajj-e-Akbar" << endl;
        else cout << "Hajj-e-Asghar" << endl;
    }
    
    return 0;
}
