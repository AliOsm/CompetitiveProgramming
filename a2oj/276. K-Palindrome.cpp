#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int freq[26];
vector<int> evensNums;

int main() {
  int t;
  cin >> t;

  string s;
  int k, odds, evens;
  bool can;
  while(t--) {
    memset(freq, 0, sizeof freq);
    evensNums.clear();
    cin >> k >> s;
    odds = evens = 0;

    for(int i = 0; i < s.length(); i++)
      freq[s[i]-'a']++;

    for(int i = 0; i < 26; i++)
      if(freq[i] % 2 == 1)
        odds++;
      else if(freq[i])
        evens++;

    if(odds > k) // if odds greater than k, then we can't solve this problem
      cout << "NO" << endl;
    else if(odds == k) // if odds equals k, then evens doesn't matter
      cout << "YES" << endl;
    else if(odds < k) { // if odds less than k, then we need evens to be greater than or equals to (k - odds)
      k -= odds;

      for(int i = 0; i < 26; i++) {
        if(freq[i] != 0)
          if(freq[i] % 2 == 0)
            evensNums.push_back(freq[i]);
          else
            evensNums.push_back(freq[i] - 1);
      }

      can = false;
      sort(evensNums.begin(), evensNums.end());

      for(int i = evensNums.size() - 1; i >= 0 && k > 0; i--) {
        if(evensNums[i] >= k) {
          can = true;
          break;
        } else
          k -= evensNums[i];
      }

      if(can)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "NO" << endl;
  }

  return 0;
}

