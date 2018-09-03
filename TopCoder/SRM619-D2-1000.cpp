/*
  Idea:
    - Greedy.
    - Imagine if the company does not employed any employee, then
      the earnings are -(sum(earning array) / 2).
    - After that try to employment each employee:
      if `sum(earning[i]) > value[i]`, then we will employment
      this employee, otherwise we do not.
    - Because we subtract the sum of all elements in `earning`
      array the dependency between employees disappears.
*/

#include <bits/stdc++.h>

using namespace std;

class EmployManager {
public:
  int maximumEarnings(vector<int> value, vector<string> earning) {
    int total = 0;
    for(int i = 0; i < value.size(); ++i)
      for(int j = 0; j < value.size(); ++j)
        total -= earning[i][j] - '0';
    total /= 2;
    
    for(int i = 0; i < value.size(); ++i) {
      int cur = 0;
      for(int j = 0; j < earning[i].size(); ++j)
        cur += earning[i][j] - '0';
      if(cur > value[i])
        total += cur - value[i];
    }
    
    return total;
  }
};
