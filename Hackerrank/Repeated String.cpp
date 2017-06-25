#include <iostream>

using namespace std;

string s;
long long n;

int main() {
	cin >> s >> n;

	int rem = n % (int)s.length();

	int noarem = 0;
	for(int i = 0; i < rem; ++i)
		if(s[i] == 'a')
			++noarem;

	long long blocks = n / (int)s.length();

	int noa = 0;
	for(int i = 0; i < (int)s.length(); ++i)
		if(s[i] == 'a')
			++noa;

	long long res = noa * blocks + noarem;

	cout << res << endl;

    return 0;
}

