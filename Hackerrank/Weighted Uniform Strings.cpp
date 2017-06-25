#include <iostream>
#include <algorithm>

using namespace std;

string s;
int const N = 1e5 + 1;
int n, tmp, cm[N];

int main() {
	cin >> s;

	cm[0] = 0;
	for(int i = 1, sum = 0; i <= (int)s.length(); ++i)
		if(i == 1) {
			sum = s[i - 1] - 'a' + 1;
			cm[i] = sum;
		} else {
			if(s[i - 1] == s[i - 2])
				sum += s[i - 1] - 'a' + 1;
			else
				sum = s[i - 1] - 'a' + 1;
			cm[i] = sum;
		}
	sort(cm, cm + (int)s.length() + 1);

	cin >> n;
	while(n-- != 0) {
		cin >> tmp;
		if(binary_search(cm, cm + (int)s.length() + 1, tmp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

    return 0;
}

