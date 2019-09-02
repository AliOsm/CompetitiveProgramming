class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int solution = 0, idx[128];
        for(int i = 0; i < 128; ++i)
            idx[i] = -1;
        
        for(int i = 0, j = 0; j < s.length(); ++j) {
            if(idx[s[j]] != -1)
                i = max(idx[s[j]] + 1, i);
            solution = max(solution, j - i + 1);
            idx[s[j]] = j;
        }
        
        return solution;
    }
};
