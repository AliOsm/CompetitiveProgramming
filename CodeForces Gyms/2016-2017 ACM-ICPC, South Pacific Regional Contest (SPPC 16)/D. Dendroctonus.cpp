/*
  Idea:
    - If there is less than two `I` points the answer is
      `No`.
    - Otherwise, for each two points check if the answer
      can be created from them, if the answer does not exist
      using only two points, add third point two the two points
      and check if the answer exist.
    - The center of the circle created from two points
      is the mid point between them.
    - The center of the circle created from three points
      is the circumcentre of them.
*/

#include <bits/stdc++.h>

using namespace std;

struct point {
  double x, y;
  bool t;
  point() {}
  point(double x, double y, char c) : x(x), y(y) {
    if(c == 'I')
      t = 0;
    else
      t = 1;
  }
};

int const N = 1e2 + 1;
int n;
point p[N];

double dist(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void lineFromPoints(point P, point Q, double &a,
                        double &b, double &c) {
    a = Q.y - P.y;
    b = P.x - Q.x;
    c = a*(P.x)+ b*(P.y);
}

void perpendicularBisectorFromLine(point P, point Q,
                 double &a, double &b, double &c) {
  point mid_point = point((P.x + Q.x)/2,
                          (P.y + Q.y)/2, 'I');

  c = -b*(mid_point.x) + a*(mid_point.y);

  double temp = a;
  a = -b;
  b = temp;
} 

point lineLineIntersection(double a1, double b1, double c1, 
                         double a2, double b2, double c2) {
  double determinant = a1*b2 - a2*b1;
  if(determinant == 0)
      return point(FLT_MAX, FLT_MAX, 'I');
  else {
    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;
    return point(x, y, 'I');
  }
}

point findCircumCenter(point P, point Q, point R) {
  double a, b, c;
  lineFromPoints(P, Q, a, b, c);
  
  double e, f, g;
  lineFromPoints(Q, R, e, f, g);
  
  perpendicularBisectorFromLine(P, Q, a, b, c);
  perpendicularBisectorFromLine(Q, R, e, f, g);
  
  point circumcenter = lineLineIntersection(a, b, c, e, f, g);
  
  return circumcenter;
}

bool solve(point c, double r) {
  bool ok = true;
  for(int k = 0; k < n; ++k) {
    if(p[k].t == 0 && dist(c, p[k]) - 1e-9 > r) {
      ok = false;
      break;
    }

    if(p[k].t == 1 && dist(c, p[k]) + 1e-9 <= r) {
      ok = false;
      break;
    }
  }

  return ok;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  scanf("%d", &n);
  int I, N;
  I = N = 0;
  for(int i = 0, x, y; i < n; ++i) {
    char c;
    scanf("%d %d %c", &x, &y, &c);
    p[i] = point(x, y, c);
    I += c == 'I';
    N += c == 'N';
  }

  if(I <= 1) {
    puts("No");
    return 0;
  }

  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      point c;
      c.x = (p[i].x + p[j].x) / 2.0;
      c.y = (p[i].y + p[j].y) / 2.0;
      double r = dist(p[i], c);

      if(solve(c, r)) {
        puts("No");
        return 0;
      }

      for(int k = j + 1; k < n; ++k) {
        point c = findCircumCenter(p[i], p[j], p[k]);
        double r = dist(p[i], c);

        if(solve(c, r)) {
          puts("No");
          return 0;
        }
      }
    }
  }

  puts("Yes");

  return 0;
}
