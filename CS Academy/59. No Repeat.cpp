#include <bits/stdc++.h>

using namespace std;

vector<char> all;

int main() {
    string s;
    int n;
    cin >> n >> s;

    int fr[26] = { 0 };
    for(int i = 0;i < n; ++i)
        fr[s[i] - 'a']++;

    for(int i = 0; i < 26; ++i)
        if(fr[i] == 1)
            all.push_back(char('a' + i));

    if(all.size() == 0)
        cout << -1 << endl;
    else {
        int idx = 1e9;
        for(int i = 0; i < all.size(); ++i)
            if(s.find(all[i]) != string::npos && s.find(all[i]) < idx)
                idx = s.find(all[i]);
        cout << s[idx] << endl;
    }

    return 0;
}

