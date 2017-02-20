#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    pair<int, int> freq[26];
    
    cin.ignore();
    while(n--) {
        for(int i = 0; i < 26; i++) {
            freq[i].first = 0;
            freq[i].second = i;
        }
        
        getline(cin, s);
        
        for(int i = 0; i < s.length(); i++)
            if(isalpha(s[i]))
                freq[tolower(s[i]) - 'a'].first++;
        
        sort(freq, freq + 26);
        
        s = "";
        for(int i = 25; i >= 0 && freq[i].first == freq[25].first; i--)
            s += char(freq[i].second + 'a');
        
        reverse(s.begin(), s.end());
        
        cout << s << endl;
    }
    
    return 0;
}
