#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long total = 0;
  string s;
  while(n--) {
    cin >> s;

    if(s == "Tetrahedron") total += 4;
    if(s == "Cube") total += 6;
    if(s == "Octahedron") total += 8;
    if(s == "Dodecahedron") total += 12;
    if(s == "Icosahedron") total += 20;
  }

  cout << total << endl;

  return 0;
}

