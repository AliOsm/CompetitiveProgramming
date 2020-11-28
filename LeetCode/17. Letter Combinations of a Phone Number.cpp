class Solution {
public:
    Solution() {
        numToChars[2] = "abc";
        numToChars[3] = "def";
        numToChars[4] = "ghi";
        numToChars[5] = "jkl";
        numToChars[6] = "mno";
        numToChars[7] = "pqrs";
        numToChars[8] = "tuv";
        numToChars[9] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        rec(0, digits, "");
        return result;
    }

private:
    string numToChars[10];
    vector<string> result;

    void rec(int i, string digits, string pattern) {
        if (i == digits.length()) {
            if (pattern.length() > 0)
                result.push_back(pattern);
            return;
        }

        for (int j = 0; j < numToChars[digits[i] - '0'].length(); ++j)
            rec(i + 1, digits, pattern + numToChars[digits[i] - '0'][j]);
    }
};
