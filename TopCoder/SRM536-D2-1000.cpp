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
