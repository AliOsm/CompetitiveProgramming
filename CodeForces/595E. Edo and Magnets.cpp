/*
  Idea:
    - First of all we need to calculate the centers of the magnets.
    - Then we can brute force on `k`, because of `k` is small
      each time we can do recursion and each time try to remove
      the top, right, buttom or left most point each time.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, k, x[N], y[N], mnw, mnh;
long long mna, t1, t2;
pair<int, int> xy[N];
deque<pair<int, int> > dx, dy;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if(a.second != b.second)
    return a.second < b.second;
  return a.first < b.first;
}

void rec(int idx) {
  if(idx == k) {
    mnw = abs(dx.front().first - dx.back().first);
    mnh = abs(dy.front().second - dy.back().second);

    t1 = mnw / 2.0;
    if(t1 == 0)
      t1 = 1;
    t2 = mnh / 2.0;
    if(t2 == 0)
      t2 = 1;

    mna = min(mna, t1 * t2);

    return;
  }

  if(!dx.empty()) {
    bool dyf, dyb;
    pair<int, int> tmp;

    dyf = dyb = false;
    tmp = dx.front();
    dx.pop_front();
    if(dy.front() == tmp) {
      dyf = true;
      dy.pop_front();
    }
    if(dy.back() == tmp) {
      dyb = true;
      dy.pop_back();
    }

    rec(idx + 1);

    dx.push_front(tmp);
    if(dyf)
      dy.push_front(tmp);
    if(dyb)
      dy.push_back(tmp);

    dyf = dyb = false;
    tmp = dx.back();
    dx.pop_back();
    if(dy.front() == tmp) {
      dyf = true;
      dy.pop_front();
    }
    if(dy.back() == tmp) {
      dyb = true;
      dy.pop_back();
    }

    rec(idx + 1);

    dx.push_back(tmp);
    if(dyf)
      dy.push_front(tmp);
    if(dyb)
      dy.push_back(tmp);
  }

  if(!dy.empty()) {
    bool dxf, dxb;
    pair<int, int> tmp;

    dxf = dxb = false;
    tmp = dy.front();
    dy.pop_front();
    if(dx.front() == tmp) {
      dxf = true;
      dx.pop_front();
    }
    if(dx.back() == tmp) {
      dxb = true;
      dx.pop_back();
    }

    rec(idx + 1);

    dy.push_front(tmp);
    if(dxf)
      dx.push_front(tmp);
    if(dxb)
      dx.push_back(tmp);

    dxf = dxb = false;
    tmp = dy.back();
    dy.pop_back();
    if(dx.front() == tmp) {
      dxf = true;
      dx.pop_front();
    }
    if(dx.back() == tmp) {
      dxb = true;
      dx.pop_back();
    }

    rec(idx + 1);

    dy.push_back(tmp);
    if(dxf)
      dx.push_front(tmp);
    if(dxb)
      dx.push_back(tmp);
  }
}

int main() {
  mna = 2e18;

  scanf("%d %d", &n, &k);
  for(int i = 0, x1, y1, x2, y2; i < n; ++i) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x[i] = ceil(((x1 + x2) / 2.0) * 2.0);
    y[i] = ceil(((y1 + y2) / 2.0) * 2.0);
  }

  for(int i = 0; i < n; ++i)
    xy[i] = make_pair(x[i], y[i]);
  sort(xy, xy + n);
  for(int i = 0; i < n; ++i)
    dx.push_back(xy[i]);

  sort(xy, xy + n, cmp);
  for(int i = 0; i < n; ++i)
    dy.push_back(xy[i]);

  rec(0);

  printf("%lld\n", mna);

  return 0;
}
