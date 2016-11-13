#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[129] = {0};
vector<pair<int, int> > res;


int main() {
	string s;
	getline(cin, s);
	
	while (true) {
		for(int i = 0; i < 129; i++) arr[i] = 0;
		res.clear();
		
		for(int i = 0, len = s.length(); i < len; i++)
			arr[int(s[i])]++;

		for(int i = 0; i < 129; i++) {
			int max = 0;
			for(int j = 0; j < 129; j++)
				if(arr[j] > arr[max])
					max = j;
			res.push_back(make_pair(max, arr[max]));
			arr[max] = -1;
		}
		
		reverse(res.begin(), res.end());
		
		for(int i = 0; i < 129; i++)
			if(res[i].second != 0) {
				cout << res[i].first << ' ' << res[i].second;
				if(i + 1 != 129)
					cout << endl;
			}
		
		if(getline(cin, s))	
			cout << endl << endl;
		else {
			cout << endl;
			break;
		}
	}

	return 0;
}
