#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int const N = 26, OO = 1e9;
int floyd[N][N];

int main() {
  for(int i = 0; i < N; i++) {
    fill(floyd[i], floyd[i] + N, OO);
    floyd[i][i] = 0;
  }
  
  string s1, s2;
  cin >> s1 >> s2;
  
  int n;
  cin >> n;
  
  char ca, cb;
  int a, b, c;
  for(int i = 0; i < n; i++) {
    cin >> ca >> cb >> c;
    a = ca - 'a';
    b = cb - 'a';
    floyd[a][b] = min(floyd[a][b], c);
  }
  
  if(s1.length() != s2.length()) {
    cout << -1 << endl;
    return 0;
  }
  
  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
  
  int res = 0, res2;
  string s = "";
  char tmp;
  for(int i = 0; i < s1.length(); i++) {
    if(floyd[s1[i]-'a'][s2[i]-'a'] == OO && floyd[s2[i]-'a'][s1[i]-'a'] == OO) {
      res2 = OO;
      for(char ch = 'a'; ch <= 'z'; ch++)
        if(floyd[s1[i]-'a'][ch-'a'] != OO && floyd[s2[i]-'a'][ch-'a'] != OO && floyd[s1[i]-'a'][ch-'a'] + floyd[s2[i]-'a'][ch-'a'] < res2) {
          res2 = floyd[s1[i]-'a'][ch-'a'] + floyd[s2[i]-'a'][ch-'a'];
          tmp = ch;
        }
      
      if(res2 == OO) {
        cout << -1 << endl;
        return 0;
      } else {
        res += res2;
        s += tmp;
      }
    } else if(s1[i] != s2[i]) {
      res += min(floyd[s1[i]-'a'][s2[i]-'a'], floyd[s2[i]-'a'][s1[i]-'a']);
      
      if(floyd[s1[i]-'a'][s2[i]-'a'] < floyd[s2[i]-'a'][s1[i]-'a'])
        s += s2[i];
      else
        s += s1[i];
      
      res2 = OO;
      for(char ch = 'a'; ch <= 'z'; ch++)
        if(floyd[s1[i]-'a'][ch-'a'] != OO && floyd[s2[i]-'a'][ch-'a'] != OO && floyd[s1[i]-'a'][ch-'a'] + floyd[s2[i]-'a'][ch-'a'] < res2) {
          res2 = floyd[s1[i]-'a'][ch-'a'] + floyd[s2[i]-'a'][ch-'a'];
          tmp = ch;
        }
      
      if(res2 < min(floyd[s1[i]-'a'][s2[i]-'a'], floyd[s2[i]-'a'][s1[i]-'a'])) {
        res -= min(floyd[s1[i]-'a'][s2[i]-'a'], floyd[s2[i]-'a'][s1[i]-'a']);
        res += res2;
        s[i] = tmp;
      }
    } else
      s += s1[i];
  }
  
  cout << res << endl;
  cout << s << endl;
  
  return 0;
}

