#include <iostream>
#include <string>
#include <set>
#include <memory.h>

using namespace std;

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

set<string> words;
set<string>::iterator it;
void DFS(trie *cursor, string word) {
  for(int i = 0; i < 26; i++)
    if(cursor->next[i] != NULL)
      DFS(cursor->next[i], word + char(i + 'a'));
  
  if(cursor->isEnd) {
    if(word != "")
      words.insert(word);
    return;
  }
}

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

void freeTrie(trie* cursor) {
	if(cursor == NULL)
		return;

	for(int i = 0; i < 26; i++)
		freeTrie(cursor->next[i]);

	delete[] cursor;
}

int main() {
  root = new trie;
  
  int n;
  cin >> n;
  
  string s;
  while(n--) {
    cin >> s;
    insert(s);
  }
  
  int m;
  cin >> m;
  
  bool pass;
  for(int c = 1; m--; c++) {
    pass = true;
    cout << "Case #" << c << ':' << endl;
    
    cin >> s;
    trie *cursor = root;
  
    for(int i = 0; i < s.length(); i++)
      if(cursor->next[s[i] - 'a'] != NULL)
        cursor = cursor->next[s[i] - 'a'];
      else {
        pass = false;
        break;
      }
    
    if(cursor == root || !pass) {
      cout << "No match." << endl;
      continue;
    }
    
    words.clear();
    DFS(cursor, "");
    
    for(it = words.begin(); it != words.end(); it++)
      cout << s << *it << endl;
  }
  
  freeTrie(root);
  
  return 0;
}

