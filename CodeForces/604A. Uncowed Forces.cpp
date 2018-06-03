/*
  Idea:
    - Implement the problem statement.
*/

#include <bits/stdc++.h>

using namespace std;

int m[5], w[5], x[] = {500, 1000, 1500, 2000, 2500}, h1, h2;

int main() {
  for(int i = 0; i < 5; ++i)
  	cin >> m[i];
  for(int i = 0; i < 5; ++i)
  	cin >> w[i];
  cin >> h1 >> h2;

  double res = 0;
  for(int i = 0; i < 5; ++i)
  	res += max(0.3 * x[i], (1.0 - m[i]/250.0) * x[i] - 50.0 * w[i]);

  res += h1 * 100;
  res -= h2 * 50;

  cout << res << endl;

  return 0;
}
