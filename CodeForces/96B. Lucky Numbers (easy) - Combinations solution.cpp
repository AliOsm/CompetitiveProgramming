#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> lucky;

void trY(long long number, int fours, int sevens) {
  if(number > 1e10) return;
  
  if(fours == sevens)
    lucky.push_back(number);
  
  trY(number * 10 + 7, fours, sevens + 1);
  trY(number * 10 + 4, fours + 1, sevens);
}

int main() {
  trY(4, 1, 0);
  trY(7, 0, 1);
  
  long long n;
  cin >> n;
  
  sort(lucky.begin(), lucky.end());
  cout << lucky[lower_bound(lucky.begin(), lucky.end(), n) - lucky.begin()] << endl;
  
  return 0;
}

