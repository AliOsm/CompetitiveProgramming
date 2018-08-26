/*
  Idea:
    - Set the value of `B` to be each integer `i` in range
      1 to `maxDen` and calculate `A` from it.
    - To compare the exact value of `number` to the new number
      (A/B) we can use extended division method.
*/

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class BestApproximationDiv2 {
  int div(int a, int b, string num) {
    int ret = 1;
    for(int i = 2; i < num.length(); ++i) {
      int t = a * 10 - b * (num[i] - '0');
      if(t >= b || t < 0)
        break;
      a = t;
      ++ret;
    }
    return ret;
  }

  public:
  
  string findFraction(int maxDen, string number) {
    stringstream ss(number);
    ss << setprecision(12);
      long double nnum;
    ss >> nnum;
    
    int mx = -1, numR, denR;
    for(int den = maxDen, num, cur; den > 0; --den) {
      num = den * nnum + 1;
      
      cur = div(num, den, number);
      if(cur >= mx) {
        mx = cur;
        numR = num;
        denR = den;
      }
          
      num -= 1;
      cur = div(num, den, number);
      if(cur >= mx) {
        mx = cur;
        numR = num;
        denR = den;
      }
      
      num -= 1;
      if(num >= 0) {
        cur = div(num, den, number);
        if(cur >= mx) {
          mx = cur;
          numR = num;
          denR = den;
        }
      }
    }
    
    string s = to_string(numR) + "/" + to_string(denR) + " has " + to_string(mx) + " exact digits";
    return s;
  }
};
