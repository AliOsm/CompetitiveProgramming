/*
  Idea:
    - It is clear to see that we need to merge low revenues first to allow
      companies with high revenues to affect the result and make it bigger.
    - So we need to sort the array, then we need to try all possible 
      possibilities to split the array in segments and then merge them.
    - To try all possible possibilities we can use dynamic programming.
    - dp[i] contains the largest possible revenue if we split the range
      `[0..i]` in the best way.
    - Then we can extend the solution for each index `i` with each possible
      length from `i + (k - 1) - 1` to `n`.
*/

#include <vector>
#include <algorithm>

using namespace std;

class MergersDivTwo {
public:
  double findMaximum(vector <int> revenues, int k) {
    sort(revenues.begin(), revenues.end());
    int n = revenues.size();

    int cs[n];
    cs[0] = revenues[0];
    for(int i = 1; i < n; ++i)
      cs[i] = cs[i - 1] + revenues[i];

    double dp[n];
    for(int i = 0; i < n; ++i)
      dp[i] = 1.0 * cs[i] / (i + 1);

    for(int i = k; i < n; ++i)
      for(int j = i + (k - 1) - 1, cnt = k; j < n; ++j, ++cnt)
        dp[j] = max(dp[j], 1.0 * (dp[i - 1] + cs[j] - cs[i - 1]) / cnt);

    return dp[n - 1];
  }
};
