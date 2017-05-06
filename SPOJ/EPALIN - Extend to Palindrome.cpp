#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

char tmp[10000001];
int f[10000001];

void kmpWork(string s) {
  for(int i = 0; i < s.length(); i++)
    f[i] = 0;
  
  f[0] = -1;
  
  for(int i = 0, j = -1; i < s.length();) {
    while(j >= 0 && s[i] != s[j]) j = f[j];
    i++, j++;
    f[i] = j;
  }
}

int main() {
  string s, rev;
  
  while(scanf("%s", tmp) != EOF) {
    s = tmp;
    rev = s;
    reverse(rev.begin(), rev.end());
    rev = rev + "#" + s;
    
    kmpWork(rev);
    
    int need = s.length() - f[rev.length() - 1] - 1;
    printf("%s", tmp);
    for(int i = need - 1; i >= 0; i--)
      putchar(tmp[i]);
    putchar('\n');
  }
  
  return 0;
}

