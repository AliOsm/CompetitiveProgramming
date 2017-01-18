#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    char line[] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
                    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
                    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
                    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/' };
    
    string s;
    getline(cin, s);
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            cout << s[i];
            continue;
        }
        
        for(int j = 1; j < sizeof line; j++)
            if(tolower(s[i]) == line[j])
                cout << line[j-2];
    }
    
    cout << endl;
    
    return 0;
}
