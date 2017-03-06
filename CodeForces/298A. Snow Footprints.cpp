#include <iostream>
#include <string>

using namespace std;

int arr[51];

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    if(s.find('R') != string::npos && s.find('L') != string::npos)
        cout << s.find('R') + 1 << ' ' << s.find('L')  << endl;
    else if(s.find('R') != string::npos) {
        int tmp = 0;
        for(int i = n - 1; i >= 0; i--)
            if(s[i] == 'R') {
                tmp = i;
                break;
            }
            
        cout << s.find('R') + 1 << ' ' << tmp + 2 << endl;
    } else {
        int tmp = 0;
        for(int i = n - 1; i >= 0; i--)
            if(s[i] == 'L') {
                tmp = i;
                break;
            }
        
        cout << tmp + 1 << ' ' << s.find('L') << endl;
    }
  
    return 0;
}

