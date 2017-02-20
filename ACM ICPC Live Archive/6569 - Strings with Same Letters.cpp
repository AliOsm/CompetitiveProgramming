#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    int freq[26];
    bool f;
    
    for(int c = 1; cin >> s1 >> s2 && s1 != "END" && s2 != "END"; c++) {
        for(int i = 0; i < 26; i++) freq[i] = 0;
        f = true;
        
        for(int i = 0; i < s1.length(); i++)
            freq[s1[i] - 'a']++;
        
        for(int i = 0; i < s2.length(); i++)
            freq[s2[i] - 'a']--;
        
        for(int i = 0; i < 26; i++)
            if(freq[i]) {
                f = false;
                break;
            }
        
        cout << "Case "<< c << ": ";
        
        if(f) cout << "same";
        else cout << "different";
        
        cout << endl;
    }
    
    return 0;
}
