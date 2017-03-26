#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  for(int i = 0; i < 10000; i++)
    arr.push_back(b + (i * a));
  
  for(int i = 0; i < 10000; i++)
    if(binary_search(arr.begin(), arr.end(), d + (i * c))) {
      cout << d + (i * c) << endl;
      return 0;
    }
  
  cout << -1 << endl;
  
  return 0;
}

