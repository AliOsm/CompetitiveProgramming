#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    string s, lower, upper;
    pair<int, int> freqa[26], freqA[26];
    
    while(getline(cin, s)) {
        for(int i = 0; i < 26; i++) {
            freqa[i].first = freqA[i].first = 0;
            freqa[i].second = freqA[i].second = i;
        }
        
        for(int i = 0; i < s.length(); i++)
            if(isalpha(s[i]))
                if(islower(s[i]))
                    freqa[s[i] - 'a'].first++;
                else
                    freqA[s[i] - 'A'].first++;
        
        sort(freqa, freqa + 26);
        sort(freqA, freqA + 26);
        
        lower = upper = "";
        
        for(int i = 25; i >= 0 && freqa[i].first == freqa[25].first; i--)
            lower += char(freqa[i].second + 'a');
        
        for(int i = 25; i >= 0 && freqA[i].first == freqA[25].first; i--)
            upper += char(freqA[i].second + 'A');
        
        reverse(lower.begin(), lower.end());
        reverse(upper.begin(), upper.end());
        
        if(freqa[25].first == freqA[25].first)
            cout << upper << lower << ' ' << freqa[25].first << endl;
        else if(freqa[25].first > freqA[25].first)
            cout << lower << ' ' << freqa[25].first << endl;
        else
            cout << upper << ' ' << freqA[25].first << endl;
    }
    
    return 0;
}
