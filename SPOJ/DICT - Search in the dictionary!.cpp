#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct trie {
  bool isEnd;
  trie *next[26];

  trie() {
    isEnd = false;
    for(int i = 0; i < 26; i++)
      next[i] = NULL;
  }
};

vector<string> words;
void DFS(trie *cursor, string word) {
  if(cursor->isEnd) {
    if(word != "")
      words.push_back(word);
  }

  for(int i = 0; i < 26; i++)
    if(cursor->next[i] != NULL)
      DFS(cursor->next[i], word + char(i + 'a'));
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

    for(int i = 0; i < words.size(); i++)
      cout << s << words[i] << endl;
  }

  freeTrie(root);

  return 0;
}
