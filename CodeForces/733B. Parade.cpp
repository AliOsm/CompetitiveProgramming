#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> l;
vector<int> r;
int res = 0, best = 0, index = 0;

int main() {
	int n;
	cin >> n;

	int total1= 0, total2 = 0;
	for(int i = 0; i < n; i++) {
		int tmp1, tmp2;
		
		cin >> tmp1 >> tmp2;
		total1 += tmp1;
		total2 += tmp2;

		l.push_back(tmp1);
		r.push_back(tmp2);
	}
	res = total1 - total2;
	best = abs(res);

	for(int i =  1; i <= n; i++) {
		total1 = total1 - l[i-1] + r[i-1];
		total2 = total2 - r[i-1] + l[i-1];

    res = total1 - total2;
		if(best < abs(res)) {
			index = i;
			best = abs(res);
		}

		total1 = total1 + l[i-1] - r[i-1];
		total2 = total2 + r[i-1] - l[i-1];
	}

	cout << index << endl;

	return 0;
}