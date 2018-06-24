/*
  Idea:
    - Calculate the maximum summation from right and left of each segment.
    - Calculate the sum of the total elements each segment.
    - Calculate the maximum subarray in each segment.
    - Then using DP we can try to start with any segment and choose
      to go to the next one or stop at it.
*/

#include <bits/stdc++.h>

using namespace std;

enum {
	F = 0, L, R, M
};

int n, m, info[51][4], a[5001], q[250001][4];
long long dp[250001][4];

long long rec(int idx, int stt) {
  if(idx >= m)
    return -2e18;
  
  long long &ret = dp[idx][stt];
  if(ret != -2e18)
    return ret;
  ret = -2e18;

  if(stt == 3) {
  	ret = q[idx][L];
  	ret = max(ret, q[idx][R] + rec(idx + 1, R));
  	ret = max(ret, rec(idx + 1, 3));
  } else if(stt != 1) {
    ret = q[idx][L];
    ret = max(ret, q[idx][F] + rec(idx + 1, F));
  }

  return ret;
}

void calc(int idx, int size) {
  int mxfar = -2e9, mxhere = 0;

  info[idx][L] = info[idx][M] = info[idx][R] = -2e9;

  for(int i = 0, sum = 0; i < size; ++i) {
  	info[idx][F] += a[i];
  	sum += a[i];
  	info[idx][L] = max(info[idx][L], sum);
  }

  for(int i = size - 1, sum = 0; i >= 0; --i) {
  	sum += a[i];
  	info[idx][R] = max(info[idx][R], sum);
  }

  for(int i = 0; i < size; ++i) {
    mxhere += a[i];
    if(mxfar < mxhere) mxfar = mxhere;
    if(mxhere < 0) mxhere = 0;
  }
  
  info[idx][M] = mxfar;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for(int i = 0, tmp; i < n; ++i) {
    scanf("%d", &tmp);
    for(int j = 0; j < tmp; ++j)
      scanf("%d", a + j);
    calc(i, tmp);
  }

  long long mx = -2e9;
  for(int i = 0, tmp; i < m; ++i) {
    scanf("%d", &tmp);
    --tmp;
    for(int j = 0; j < 4; ++j) {
    	q[i][j] = info[tmp][j];
    	mx = max(mx, 1ll * info[tmp][M]);
    }
  }

  for(int i = 0; i < 250001; ++i)
  	for(int j = 0; j < 4; ++j)
  		dp[i][j] = -2e18;
  printf("%lld\n", max(mx, rec(0, 3)));

  return 0;
}
