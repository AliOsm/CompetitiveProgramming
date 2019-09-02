class Solution {
public:
    string longestPalindrome(string s) {
        int b = 0, e = 0;
        
        for(int i = 0, j, k; i < s.length(); ++i) {
            j = i, k = i;
            while(j >= 0 && k < s.length() && s[j] == s[k])
                --j, ++k;
            ++j, --k;
            if(k - j + 1 > e - b + 1)
                b = j, e = k;
            
            
            j = i, k = i + 1;
            while(j >= 0 && k < s.length() && s[j] == s[k])
                --j, ++k;
            ++j, --k;
            if(k - j + 1 > e - b + 1)
                b = j, e = k;
        }
        
        return s.substr(b, e - b + 1);
    }
};
