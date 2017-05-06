#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k;
string s;
vector<int> subs;

bool can(int mid) {
  int tmp, j = 0;
  
  for(int i = 0; i < k; ++i) {
    tmp = 0;
    
    while(j < subs.size()) {
      if(tmp + subs[j] <= mid) {
        tmp += subs[j];
        ++j;
      } else break;
    }
  }
  
  return j == subs.size();
}

int main() {
  cin >> k;
  cin.ignore();
  getline(cin, s);
  
  string tmp = "";
  for(int i = 0; i < s.length(); ++i) {
    tmp += s[i];
    if(s[i] == '-' || s[i] == ' ') {
      subs.push_back(tmp.length());
      tmp = "";
    }
  }
  subs.push_back(tmp.length());
  
  int l = 0, r = 1e9, mid, res = -1;
  while(l <= r) {
    mid = (l + r) / 2;
    if(can(mid)) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  
  cout << res << endl;
  
  return 0;
}

