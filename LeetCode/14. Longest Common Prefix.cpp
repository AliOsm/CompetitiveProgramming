class Solution {
public:
    Solution() {
        root = new trie;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs.size(); ++i) {
            prefix = insert(strs[i], strs.size());
        }
        
        return prefix;
    }

private:
    struct trie {
        int prefixes;
        trie *next[26];

        trie() {
            prefixes = 0;
            for (int i = 0; i < 26; ++i)
                next[i] = NULL;
        }
    };

    trie *root;

    string insert(string s, int strCount) {
        string prefix = "";
        trie *cursor = root;

        for(int i = 0; s[i] != '\0'; ++i) {
            int number = s[i] - 'a';

            if(cursor->next[number] == NULL)
                cursor->next[number] = new trie;

            cursor = cursor->next[number];
            cursor->prefixes++;
            
            if (cursor->prefixes == strCount) {
                prefix += s[i];
            }
        }
        
        return prefix;
    }
};
