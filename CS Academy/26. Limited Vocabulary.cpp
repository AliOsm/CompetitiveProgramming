#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  string s;
  int res = 0;
  while(n--) {
    cin >> s;
    
    int freq[26] = {};
    for(int i = 0; i < s.length(); i++)
      freq[s[i] - 'a']++;
    
    int dist = 0;
    for(int i = 0; i < 26; i++)
      if(freq[i])
        dist++;
    
    if(dist <= k && res < s.length())
      res = s.length();
  }
  
  if(res == 0) cout << -1 << endl;
  else cout << res << endl;

  return 0;
}
