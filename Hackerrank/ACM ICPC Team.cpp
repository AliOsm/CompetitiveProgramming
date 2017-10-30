#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

int str_to_int(string t) {
	int res = 0;
	for(int i = 0; i < (int)t.size(); ++i) {
		res *= 10;
		res += t[i] - '0';
	}
	return res;
}

int n, m;
vector<string> persons;
string tmp;

int same(string &a, string &b) {
	int res = 0;
	for(int i = 0; i < m; ++i) {
		res += (a[i] == '1' || b[i] == '1');
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		persons.push_back(tmp);
	}

	int mx = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(i != j)
				mx = max(mx, same(persons[i], persons[j]));

	int res = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(i != j && same(persons[i], persons[j]) == mx)
				++res;

	printf("%d\n%d\n", mx, res / 2);

	return 0;
}

