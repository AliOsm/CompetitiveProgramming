#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    pair<int, int> freq[129];
    bool blankline = false;
    
    while(getline(cin, s)) {
        if(blankline) cout << endl;
        
        for(int i = 0; i < 129; i++) {
            freq[i].first = 0;
            freq[i].second = i;
        }
        
        for(int i = 0; i < s.length(); i++)
            freq[int(s[i])].first++;
        
        sort(freq, freq + 129);
        
        for(int i = 0, j, k; i < 129; i++)
            if(freq[i].first) {
                j = i;
                
                while(freq[j].first == freq[i].first && j + 1 <= 129) j++;
                j--;
                
                k = j;
                
                while(j >= i) {
                    cout << freq[j].second << ' ' << freq[j].first << endl;
                    j--;
                }
                
                i = k;
            }
        
        blankline = true;
    }
    
    return 0;
}
