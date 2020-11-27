#include <bits/stdc++.h>
 
using namespace std;
 
int n;
string s;
set<string> st;
 
int main() {
  st.insert("ABSINTH");
  st.insert("BEER");
  st.insert("BRANDY");
  st.insert("CHAMPAGNE");
  st.insert("GIN");
  st.insert("RUM");
  st.insert("SAKE");
  st.insert("TEQUILA");
  st.insert("VODKA");
  st.insert("WHISKEY");
  st.insert("WINE");
 
  scanf("%d", &n);
 
  int res = 0;
  for(int i = 0; i < n; ++i) {
    cin >> s;
    if(isdigit(s[0])) {
      if(s.length() == 1 || (s.length() == 2 && s[0] == '1' && s[1] < '8'))
        ++res;
    } else {
      res += st.count(s);
    }
  }
 
  printf("%d\n", res);
 
  return 0;
}                                                                                                                                                          
