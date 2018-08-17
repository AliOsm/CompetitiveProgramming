/*
  Idea:
    - DP on Trie
*/

#include <bits/stdc++.h>

using namespace std;

struct trie {
  bool end;
  int rep;
  trie *nxt[26];
  trie() {
    end = false;
    rep = 0;
    for(int i = 0; i < 26; ++i)
      nxt[i] = NULL;
  }
};

int const N = 3e5 + 10, MOD = 20071027;
char s[N], tmp[N];
int n, len, dp[N];
trie *root;

void insert() {
  int len = strlen(tmp);
  trie *cur = root;
  for(int i = 0, num; i < len; ++i) {
    num = tmp[i] - 'a';
    if(cur->nxt[num] == NULL)
      cur->nxt[num] = new trie();
    cur = cur->nxt[num];
  }
  ++cur->rep;
  cur->end = true;
}

void free_trie(trie *cur) {
  if(cur == NULL)
    return;
  for(int i = 0; i < 26; ++i)
    free_trie(cur->nxt[i]);
  delete[] cur;
}

int rec(int idx) {
  if(idx == len)
    return 1;

  int &ret = dp[idx];
  if(ret != -1)
    return ret;
  ret = 0;

  trie *cur = root;

  for(int i = idx, num; i < len; ++i) {
    num = s[i] - 'a';

    if(cur->nxt[num] == NULL)
      break;
    cur = cur->nxt[num];

    if(cur->rep)
      ret = (ret + rec(i + 1)) % MOD;
  }

  return ret;
}

int main() {
  int kase = 1;
  while(scanf("%s", s) != EOF) {
    len = strlen(s);

    scanf("%d", &n);
    root = new trie();
    for(int i = 0; i < n; ++i) {
      scanf("%s", tmp);
      insert();
    }

    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", kase++, rec(0));

    free_trie(root);
  }
  
  return 0;
}
