#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	map<int, int> mp;
	for(int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		++mp[tmp];
	}

	vector<pair<int, int> > freq;
	freq.resize(3);
	int cnt = 0;
	for(auto&& e:mp)
		freq[cnt++] = make_pair(e.first, e.second);

	if(mp.size() == 2 && freq[1].first - freq[0].first == 2) {
		int mn = min(freq[0].second, freq[1].second);
		int mx = max(freq[0].second, freq[1].second);

		cout << n - (2 * mn) << endl;

		for(int i = 0; i < 2 * mn; ++i)
			cout << freq[0].first + 1 << ' ';

		for(int i = 0; i < mx - mn; ++i)
			if(freq[0].second > freq[1].second)
				cout << freq[0].first << ' ';
			else
				cout << freq[1].first << ' ';
		cout << endl;

		return 0;
	}

	if(mp.size() <= 2) {
		cout << n << endl;

		for(int i = 0; i < freq.size(); ++i)
			for(int j = 0; j < freq[i].second; ++j)
				cout << freq[i].first << ' ';
		cout << endl;

		return 0;
	}
	
	int mn = min(freq[0].second, freq[2].second);
	int mx = max(freq[0].second, freq[2].second);

	if(freq[1].second + mx - mn <= mx + mn + (freq[1].second & 1)) {
		int need = freq[1].second + (mn * 2);

		cout << freq[1].second + mx - mn << endl;

		for(int i = 0; i < mx - mn; ++i)
			if(mx == freq[0].second)
				cout << freq[0].first << ' ';
			else
				cout << freq[2].first << ' ';

		for(int i = 0; i < need; ++i)
			cout << freq[1].first << ' ';
		cout << endl;
	} else {
		bool t = true, p = false;

		if(freq[1].second & 1) {
			p = true;
			freq[1].second--;
		}

		cout << mx + mn + p << endl;

		for(int i = 0; i < freq[0].second; ++i)
			cout << freq[0].first << ' ';

		for(int i = 0; i < freq[2].second; ++i)
			cout << freq[2].first << ' ';

		for(int i = 0; i < freq[1].second; ++i)
			if(t) {
				cout << freq[0].first << ' ';
				t = !t;
			} else {
				cout << freq[2].first << ' ';
				t = !t;
			}

		if(p)
			cout << freq[1].first << ' ';
		cout << endl;
	}

	return 0;
}