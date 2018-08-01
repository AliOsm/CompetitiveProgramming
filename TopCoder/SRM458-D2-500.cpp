#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class BouncingBalls {
public:
  double expectedBounces(vector<int> x, int T) {
    sort(x.begin(), x.end());

    double res = 0;
    for(int i = 0; i < x.size(); ++i)
      for(int j = i + 1; j < x.size(); ++j)
        if(abs(x[i] - x[j]) <= 2 * T)
          res += 0.25;

    return res;
  }
};
