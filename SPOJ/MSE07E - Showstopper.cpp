/*
  Idea:
    - Binary Search
    - If the summation of the range from low to mid is
      even, then the required number is in range from
      mid + 1 to high, otherwise the required number
      is in range from low to mid.
*/

#include <bits/stdc++.h>

using namespace std;

vector<long long> x, y, z;

int main() {
  string s;
  while(!cin.eof()) {
    getline(cin, s);
    while(s[0] != '\r' && s[0] != ' ' && s[0] != '\0') {
      long long tx, ty, tz;
      sscanf(s.c_str(),"%lld %lld %lld", &tx, &ty, &tz);
      x.push_back(tx);
      y.push_back(ty);
      z.push_back(tz);
      
      if(cin.eof())
        break;

      getline(cin, s);
    }

    if(x.empty())
      continue;

    long long tot = 0, l = 0, r = 1e12, mid, s, e;

    while(l < r) {
      mid = (l + r) / 2;

      tot = 0;
      for(int i = 0; i < x.size(); ++i)
        if(x[i] <= mid)
          tot += (x[i] - min(y[i], mid)) / z[i] + 1;

      if(tot % 2 == 0)
        l = mid + 1;
      else
        r = mid;
    }

    long long rep = 0;
    for(int i = 0, k; i < x.size(); ++i)
      if(l <= y[i] && l >= x[i] && (l - x[i]) % z[i] == 0)
        ++rep;

    if(rep == 0)
      puts("no corruption");
    else
      printf("%lld %lld\n", l, rep);

    x.clear();
    y.clear();
    z.clear();
  }

  return 0;
}
