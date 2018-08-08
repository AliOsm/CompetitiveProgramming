#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 10;

struct point {
  double x, y, z;

  point() {}

  point(double x, double y, double z) : x(x), y(y), z(z) {}

  bool operator==(const point &p) const {
    return x == p.x && y == p.y && z == p.z;
  }

  point operator-(const point &p) const {
    return point(x - p.x, y - p.y, z - p.z);
  }

  point operator+(const point &p) const {
    return point(x + p.x, y + p.y, z + p.z);
  }

  point operator*(const double &o) const {
    return point(x * o, y * o, z * o);
  }

  double dist(const point &p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
  }
} points[N];
point p;

int n;
double vp, vs, t[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i <= n; ++i)
    scanf("%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z);
  scanf("%lf %lf", &vp, &vs);
  scanf("%lf %lf %lf", &p.x, &p.y, &p.z);

  if(p == points[0]) {
    puts("YES");
    puts("0.0000000000");
    printf("%0.10lf %0.10lf %0.10lf\n", p.x, p.y, p.z);
    return 0;
  }

  for(int i = 1; i <= n; ++i)
    t[i] = points[i].dist(points[i - 1]) / vs + t[i - 1];

  for(int i = 1; i <= n; ++i) {
    if(p.dist(points[i]) / vp - 1e-9 < t[i]) {
      double l = 0, r = 1, mid;
      point res;
      for(int j = 0; j < 100; ++j) {
        mid = (l + r) / 2;
        point cur = points[i - 1] + (points[i] - points[i - 1]) * mid;

        if(p.dist(cur) / vp - 1e-15 < points[i - 1].dist(cur) / vs + t[i - 1])
          res = cur, r = mid;
        else
          l = mid;
      }

      puts("YES");
      printf("%0.10lf\n", p.dist(res) / vp);
      printf("%0.10lf %0.10lf %0.10lf\n", res.x, res.y, res.z);

      return 0;
    }
  }

  puts("NO");

  return 0;
}
