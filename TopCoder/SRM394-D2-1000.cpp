/*
  Idea:
    - Using sieve loops style we can produce the devisors for each
      integer `i` from `a` to `a + b` and check if it is cool or not.
*/

class ProperDivisors {
public:
  int analyzeInterval(int a, int b, int n) {
    int e = a + b;
    long long p, res = 0;
    bool ok;
    for(int i = 1; i <= e; ++i) {
      for(int j = i * 2; j <= e; j += i) {
        p = 1;
        ok = true;
        for(int k = 0; k < n; ++k) {
          p *= i;
          if(p > j) {
            ok = false;
            break;
          }
        }
        if(ok && j % p == 0)
          continue;
        if(j >= a && j <= e)
          ++res;
      }
    }
    return res;
  }
};
