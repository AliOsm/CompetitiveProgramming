#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int const N = 1e6 + 1;
int n, m, arr[N];

string buildString() {
  string s = "";
  for(int i = 0; i < n; i++) {
    s += "0";
    arr[i] == 1 ? s += "1" : s += "11";
  }
  return s;
}

int main() {
  cin >> n >> m;
  fill(arr, arr + n, 1);
  
  int tmp = m;
  m -= n;
  
  if(m == 0)
    cout << buildString() << endl;
  else if(m < 0) {
    if(n - tmp == 1) {
      string tmp = buildString();
      tmp.pop_back();
      cout << tmp << endl;
    } else
      cout << -1 << endl;
  } else {
    for(int i = 0; i < n; i++) {
      if(!m) break;
      arr[i]++;
      m--;
    }
    
    if(m > 2) cout << -1 << endl;
    else if(m == 0) cout << buildString() << endl;
    else if(m == 1) cout << 1 << buildString() << endl;
    else if(m == 2) cout << 11 << buildString() << endl;
  }
  
  return 0;
}

