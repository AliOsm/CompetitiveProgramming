/*
  Idea:
    - Calculate the probability for all teams to reach the semi-final.
    - Based on the previus step, calculate the probability for all teams
      to reach the final.
    - Based on the previus step, calculate the probability for all teams
      to win the cup.
*/

#include <bits/stdc++.h>

using namespace std;

map<int, string> its;
double props[17][17], prop[3][17];

void calc1(int dst, int op, int o1, int o2) {
	prop[0][dst] = props[dst][op] *
							 		(props[o1][o2] * props[dst][o1] +
							  	 props[o2][o1] * props[dst][o2]);
}

void calc2(int s1, int e1, int s2, int e2, int idx) {
	for(int i = s1; i <= e1; ++i)
  	for(int j = s2; j <= e2; ++j)
  		prop[idx][i] += prop[idx - 1][i] * prop[idx - 1][j] * props[i][j];
}

int main() {
  string name;
  for(int i = 1; i <= 16; ++i) {
  	cin >> name;
  	its[i] = name;
  }

  for(int i = 1; i <= 16; ++i)
  	for(int j = 1; j <= 16; ++j)
  		cin >> props[i][j], props[i][j] /= 100;

  // semi-final
  // branch 1
  calc1(1, 2, 3, 4);
  calc1(2, 1, 3, 4);
  calc1(3, 4, 1, 2);
  calc1(4, 3, 1, 2);
  // branch 2
  calc1(5, 6, 7, 8);
  calc1(6, 5, 7, 8);
  calc1(7, 8, 5, 6);
  calc1(8, 7, 5, 6);
  // branch 3
  calc1(9, 10, 11, 12);
  calc1(10, 9, 11, 12);
  calc1(11, 12, 9, 10);
  calc1(12, 11, 9, 10);
  // branch 4
  calc1(13, 14, 15, 16);
  calc1(14, 13, 15, 16);
  calc1(15, 16, 13, 14);
  calc1(16, 15, 13, 14);

  // final
  // branch 1
  calc2(1, 4, 5, 8, 1);
  // branch 2
  calc2(5, 8, 1, 4, 1);
  // branch 3
  calc2(9, 12, 13, 16, 1);
  // branch 4
  calc2(13, 16, 9, 12, 1);

  // win
  // branch 1
  calc2(1, 8, 9, 16, 2);
  // branch 2
  calc2(9, 16, 1, 8, 2);

  // answer
  for(int i = 1; i <= 16; ++i)
  	cout << left << setw(10) << its[i] << " p=" << fixed << setprecision(2) << prop[2][i] * 100 << '%' << endl;

  return 0;
}
