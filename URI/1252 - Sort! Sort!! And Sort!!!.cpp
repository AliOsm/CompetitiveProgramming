#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<pair<int, int> > arr;

bool comp(pair<int, int> a, pair<int, int> b) {
	if(a.second != b.second)
		return a.second < b.second;
	else
		if(abs(a.first) % 2 == 1 && abs(b.first) % 2 == 0)
			return true;
		else if(abs(a.first) % 2 == 0 && abs(b.first) % 2 == 1)
			return false;
		else if(abs(a.first) % 2 == 1 && abs(b.first) % 2 == 1)
			return a.first > b.first;
		else
			return a.first < b.first;
}

int main() {
    while(cin >> n >> m && n && m) {
    	arr.clear();
    	
	    for(int i = 0; i < n; i++) {
	    	int tmp;
	    	cin >> tmp;
	    	arr.push_back(make_pair(tmp, tmp % m));
	    }
	    
	    sort(arr.begin(), arr.end(), comp);
	    
	    cout << n << ' ' << m << endl;
	    for(int i = 0; i < n; i++)
	    	cout << arr[i].first << endl;
    }
    
    cout << "0 0" << endl;

    return 0;
}
