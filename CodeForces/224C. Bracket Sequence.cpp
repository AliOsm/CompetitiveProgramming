/*
  Idea:
    - Extract all right substrings in the origin string then try to concatinate them.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
char s[N];
int n, cs[N];
stack<pair<int, int> > st;

int main() {
  scanf("%s", s);
  n = strlen(s);

  for(int i = 0; i < n; ++i) {
    if(s[i] == '(' || s[i] == '[')
      st.push({i, s[i]});
    else {
      if(!st.empty() && 
         ((s[i] == ']' && '[' == st.top().second) ||
          (s[i] == ')' && '(' == st.top().second))) {
        cs[st.top().first] = 1;
        cs[i] = 1;
        st.pop();
      } else {
        while(!st.empty())
          st.pop();
      }
    }
  }

  int res = 0, start = -1, end = -1;
  for(int i = 0; i < n; ++i)
    if(cs[i] == 1) {
      int j = i;
      for(; j < n && cs[j] == 1; ++j);
      int cnt = 0;
      for(int k = i; k < j; ++k)
        cnt += s[k] == '[';
      if(cnt > res)
        res = cnt, start = i, end = j;
      i = j;
    }

  if(res > 0) {
    printf("%d\n", res);
    for(int i = start; i < end; ++i)
      putchar(s[i]);
    puts("");
  } else
    puts("0\n");

  return 0;
}
