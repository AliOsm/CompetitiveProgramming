#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int total, words;

struct trie {
  bool isEnd;
  int prefixes;
  trie *next[26];
  
  trie() {
    isEnd = false;
    prefixes = 0;
    for(int i = 0; i < 26; i++)
      next[i] = NULL;
  }
};

trie *root;

void insert(string s) {
  trie *cursor = root;
  
  int number;
  for(int i = 0; i < s.length(); i++) {
    number = s[i] - 'a';
    
    if(cursor->next[number] == NULL)
      cursor->next[number] = new trie;
    
    cursor = cursor->next[number];
    cursor->prefixes++;
  }
  
  cursor->isEnd = true;
}

void freeTrie(trie *cursor, int pre_prefixes) {
  if(pre_prefixes != cursor->prefixes)
    total += cursor->prefixes;
  
  for(int i = 0; i < 26; i++)
    if(cursor->next[i] != NULL)
      freeTrie(cursor->next[i], cursor->prefixes);
  
  delete[] cursor;
}

int main() {
  int n;
  string s;
  
  while(cin >> n) {
    root = new trie;
    total = words = 0;
    
    for(int i = 0; i < n; i++, words++) {
      cin >> s;
      insert(s);
    }
    
    freeTrie(root, 0);
    cout << fixed << setprecision(2) << 1.0 * total / words << endl;
  }
  
  return 0;
}

