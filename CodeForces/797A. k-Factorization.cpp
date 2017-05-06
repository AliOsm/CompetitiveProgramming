#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  int tmp = k;
  
  vector<int> d;
  int i = 2;
  while(k) {
    if(i > 100000 || k == 1)
      break;
    
    if(n % i == 0) {
      d.push_back(i);
      n /= i;
      --k;
    } else
      ++i;
  }
  
  if(n != 1)
    d.push_back(n);
  
  if(d.size() != tmp) {
    cout << -1 << endl;
    return 0;
  }
  
  for(int i = 0; i < d.size(); i++) {
    if(i) cout << ' ';
    cout << d[i];
  }
  cout << endl;
  
  return 0;
}

