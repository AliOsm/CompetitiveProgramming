/*
  Idea:
    - Dynamic programming.
    - msk: represents what is the numbers taken till now.
    - idx: represents where we are now.
    - The dynamic programming result has duplicate permutations,
      so we need to divide the result with the factorial of the
      repetitions of each number.
*/

#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

class Deranged {
public:
  static long long dp[(1 << 16)][16];

  long long numDerangements(vector <int> nums) {
    sort(nums.begin(), nums.end());
    memset(dp, -1, sizeof dp);
    long long ret = rec(0, 0, nums);

    int fr[16] = {0};
    for(int i = 0; i < nums.size(); ++i)
      ++fr[nums[i]];

    for(int i = 0; i < 16; ++i)
      ret /= fact(fr[i]);

    return ret;
  }
  
  long long rec(int idx, int msk, vector<int> &nums) {
    if(__builtin_popcount(msk) == int(nums.size()))
      return 1;

    long long &ret = dp[msk][idx];
    if(ret != -1)
      return ret;
    ret = 0;
    
    for(int i = 0; i < nums.size(); ++i)
      if(((msk >> i) & 1) == 0 && nums[idx] != nums[i])
        ret += rec(idx + 1, msk | (1 << i), nums);
    
    return ret;
  }

  long long fact(int x) {
    long long f = 1;
    for(int i = 2; i <= x; ++i)
      f *= i;
    return f;
  }
};

long long Deranged::dp[][16] = {0};
