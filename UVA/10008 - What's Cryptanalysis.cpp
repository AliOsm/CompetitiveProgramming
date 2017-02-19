#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    string s;
    pair<int, int> freq[26];
    for(int i = 0; i < 26; i++) {
        freq[i].first = 0;
        freq[i].second = i;
    }
 
    cin.ignore();
    while(t--) {
        getline(cin, s);
 
        for(int i = 0; i < s.length(); i++)
            if(isalpha(s[i]))
                freq[tolower(s[i]) - 'a'].first++;
    }
 
    sort(freq, freq + 26);
 
    for(int i = 25, j, k; i >= 0; i--)
        if(freq[i].first) {
            j = i;
 
            while(freq[j].first == freq[i].first && j - 1 >= 0) j--;
            j++;
 
            k = j;
 
            while(j <= i) {
                cout << char(freq[j].second + 'A') << ' ' << freq[j].first << endl;
                j++;
            }
 
            i = k;
        } else if(freq[i].first == 0)
            break;
 
    return 0;
}
