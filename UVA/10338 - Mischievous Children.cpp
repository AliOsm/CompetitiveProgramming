#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    int freq[26];
    
    for(int c = 1; n--; c++) {
        for(int i = 0; i < 26; i++) freq[i] = 0;
        
        cin >> s;
        
        for(int i = 0; i < s.length(); i++)
            freq[tolower(s[i]) - 'a']++;
        
        long long res = 1;

        for(int i = 2; i <= s.length(); i++)
            res *= i;
        
        for(int i = 0; i < 26; i++)
            if(freq[i]) {
                long long tmp = 1;
                for(int j = 2; j <= freq[i]; j++)
                    tmp *= j;
                res /= tmp;
            }
        
        cout << "Data set " << c << ": " << res << endl;
    }
    
    return 0;
}
