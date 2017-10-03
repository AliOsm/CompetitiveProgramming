#include <bits/stdc++.h>

using namespace std;

struct trie {
  trie *nxt[2];
  int pre[2];
  
  trie() {
    nxt[0] = nxt[1] = NULL;
    pre[0] = pre[1] = 0;
  }
};

int t, n, k;
long long res;
trie *root;

void insert(int m) {
  trie *cur = root;
  for(int i = 20, num; i >= 0; --i) {
    num = (m >> i) & 1;
    ++cur->pre[num];
    if(cur->nxt[num] == NULL)
      cur->nxt[num] = new trie();
    cur = cur->nxt[num];
  }
}

long long find(long long num) {
  long long ret = 0;
  trie *cur = root;
  for(int i = 20, num1, num2; i >= 0; --i) {
    num1 = (k >> i) & 1;
    num2 = (num >> i) & 1;
    
    if(num1) {
      ret += cur->pre[num2];
      if(cur->nxt[!num2] == NULL)
        return ret;
      cur = cur->nxt[!num2];
    } else {
      if(cur->nxt[num2] == NULL)
        return ret;
      cur = cur->nxt[num2];
    }
  }
  return ret;
}

void freeTrie(trie *cur) {
  if(cur == NULL)
    return;
  for(int i = 0; i < 2; ++i)
    freeTrie(cur->nxt[i]);
  delete [] cur;
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
    res = 0;
    root = new trie();
    insert(0);
    
    scanf("%d %d", &n, &k);
    for(int i = 0, in, num, tmp = 0; i < n; ++i) {
      scanf("%d", &in);
      num = (in ^ tmp);
      res += find(num);
      insert(num);
      tmp = num;
    }
    printf("%lld\n", res);
    
    freeTrie(root);
  }
  
  return 0;
}
