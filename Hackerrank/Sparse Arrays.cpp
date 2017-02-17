#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;

int main() {
    int n;
    string tmp;
    
    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++) {
        getline(cin, tmp);
        m[tmp]++;
    }
    
    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++) {
        getline(cin, tmp);
        cout << m[tmp] << endl;
    }
    
    return 0;
}
