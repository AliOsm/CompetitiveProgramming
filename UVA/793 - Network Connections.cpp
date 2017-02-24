#include <iostream>

using namespace std;

int const N = 1e6 + 1;
int ds[N];

int find(int x) {
    return (ds[x] == x ? x : (ds[x] = find(ds[x])));
}

int main() {
    bool blankline = false;

    int t;
    cin >> t;

    string s, tmp;
    cin.ignore();
    getline(cin, s);

    int n, a, b, yes, no;
    while(t--) {
        if(blankline)
            cout << endl;

        yes = no = 0;

        cin >> n;

        for(int i = 0; i < n; i++)
            ds[i] = i;

        cin.ignore();
        while(getline(cin, s) && s != "") {
        	tmp = s.substr(2, s.find(' ', 2) - s.find(' ') - 1);

        	a = 0;
        	for(int i = 0; i < (int)tmp.length(); i++) {
        		a *= 10;
        		a += tmp[i] - '0';
        	}

        	tmp = s.substr(s.find(' ', 2) + 1);

        	b = 0;
			for(int i = 0; i < (int)tmp.length(); i++) {
				b *= 10;
				b += tmp[i] - '0';
			}

            a--; b--;

            if(s[0] == 'c') {
                ds[find(a)] = find(b);
            } else {
                if(find(a) == find(b))
                    yes++;
                else
                    no++;
            }
        }

        cout << yes << ',' << no << endl;

        blankline = true;
    }

    return 0;
}
