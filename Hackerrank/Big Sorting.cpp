#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> a;

bool cmp(string a, string b) {
	if(a.length() < b.length())
		return true;

	if(a.length() > b.length())
		return false;

	return a < b;
}

int main() {
	int n;
	cin >> n;
	a.clear();
	a.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end(), cmp);

	for(int i = 0; i < n; ++i)
		cout << a[i] << endl;

	return 0;
}

