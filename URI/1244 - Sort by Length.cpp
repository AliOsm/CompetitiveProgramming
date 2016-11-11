#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, vector<string> > m;

int main() {
    int t;
    cin >> t;
    
    cin.ignore();
    while(t--) {
        m.clear();
        string s;
        getline(cin, s);
        s += ' ';
        
        string tmp = "";
        for(int i = 0, len = s.length(); i < len; i++)
            if(s[i] == ' ') {
                m[tmp.length()].push_back(tmp);
                tmp = "";
            } else
                tmp += s[i];
        
        map<int, vector<string> >::iterator it;
        for(it = (m.end()--); it != m.begin(); it--)
            for(int i = 0, len = it->second.size(); i < len; i++)
                cout << it->second[i] << ' ';
        
        for(int i = 0, len = it->second.size(); i < len; i++)
            cout << it->second[i] << (i + 1 != len ? " " : "");
        
        cout << endl;
    }
    
    return 0;
}
