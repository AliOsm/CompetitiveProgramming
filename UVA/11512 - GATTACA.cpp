#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

char s[1001];
int length;
bool go;
string res;

struct trie {
  int prefixes;
  trie *next[4];
  trie() {
    prefixes = 0;
    for(int i = 0; i < 4; i++)
      next[i] = NULL;
  }
};

trie *root;

void insert(int index) {
  trie *cursor = root;
  
  int number;
  for(int i = index; s[i] != '\0'; i++) {
    number = s[i] - '0';
    
    if(cursor->next[number] == NULL)
      cursor->next[number] = new trie;
    
    cursor = cursor->next[number];
    cursor->prefixes++;
    
    if(cursor->prefixes > 1)
      length = max(length, i - index + 1);
  }
}

void calc(trie *cursor, int length) {
  if(length == ::length) {
    for(int i = 0; i < res.length(); i++) {
      if(res[i] == '0') putchar('A');
      else if(res[i] == '1') putchar('C');
      else if(res[i] == '2') putchar('G');
      else if(res[i] == '3') putchar('T');
    }
    
    printf(" %d\n", cursor->prefixes);
    go = false;
    return;
  }
  
  for(int i = 0; go && i < 4; i++)
    if(cursor->next[i] != NULL && cursor->next[i]->prefixes > 1) {
      res += char(i + '0');
      calc(cursor->next[i], length + 1);
      res.pop_back();
    }
}

void freeTrie(trie *cursor) {
  for(int i = 0; i < 4; i++)
    if(cursor->next[i] != NULL)
      freeTrie(cursor->next[i]);
  delete[] cursor;
}

int main() {
  int t;
  scanf("%d", &t);
  
  while(t--) {
    length = 0;
    go = true;
    res = "";
    root = new trie;
    
    scanf("%s", s);
    
    for(int i = 0; s[i] != '\0'; i++) {
      if(s[i] == 'A') s[i] = '0';
      else if(s[i] == 'C') s[i] = '1';
      else if(s[i] == 'G') s[i] = '2';
      else if(s[i] == 'T') s[i] = '3';
    }
    
    for(int i = 0; s[i] != '\0'; i++)
      insert(i);
    
    if(length != 0) calc(root, 0);
    else puts("No repetitions found!");
    
    freeTrie(root);
  }
  
  return 0;
}

