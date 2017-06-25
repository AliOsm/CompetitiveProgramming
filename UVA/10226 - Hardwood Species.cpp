#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

map<string, int> m;

int main() {
    int n;
    cin >> n;

    string s;
    cin.ignore();
    getline(cin, s);

    cout << fixed << setprecision(4);

    while(n--) {
    	m.clear();
    	int c = 0;

    	while(getline(cin, s) && s.length() && (c = c + 1))
            m[s]++;

    	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    		cout << it->first << ' ' << 100.0 / c * it->second << endl;

    	if(n)
    		cout << endl;
    }

    return 0;
}
