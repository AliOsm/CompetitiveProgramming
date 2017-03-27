#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) arr.push_back(i);
  
  int led = 0, tmp;
  while(k--) {
    cin >> tmp;
    tmp %= n;
    
    led += tmp;
    led %= n;
    cout << arr[led];
    if(k) cout << ' ';
    arr.erase(arr.begin() + led);
    n--;
  }
  
  cout << endl;
  
  return 0;
}

