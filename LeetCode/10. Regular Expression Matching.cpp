class Solution {
private:
    static int const N = 1e2 + 1;
    int dp[N][N];

public:
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, s, p);
    }
    
    bool rec(int i, int j, string &s, string &p) {
        if(j == p.length())
            return i == s.length();
        
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        
        bool match = false;
        if(i < s.length() && (s[i] == p[j] || p[j] == '.'))
            match = true;
        
        if(j + 1 < p.length() && p[j + 1] == '*')
            ret = (rec(i, j + 2, s, p) || match && rec(i + 1, j, s, p));
        else
            ret = match && rec(i + 1, j + 1, s, p);
        
        return ret;
    }
};
