#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int freq[26] = {0};
    for(int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;
    
    int c = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i])
            c++;
    
    if(c % 2) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
    
    return 0;
}
