#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr;
	int res = 0;
	string s;
	cin >> s;
	
	arr.push_back(-1);
	for(int i = 0, len = s.length(); i < len; i++)
		if(s[i] == 'A' || s[i] == 'E' ||
		   s[i] == 'U' || s[i] == 'I' ||
		   s[i] == 'O' || s[i] == 'Y')
		    arr.push_back(i);
	arr.push_back(s.length());
		    
	for(int i = 0, len = arr.size() - 1; i < len; i++)
		res = max(res, arr[i+1] - arr[i]);
	
	if(arr.size() == 2) {
	    cout << s.length() + 1 << endl;
	else
			if(!res)
				cout << 1 << endl;
			else
				cout << res << endl;
    
    return 0;
}
