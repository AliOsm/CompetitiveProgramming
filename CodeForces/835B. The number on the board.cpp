#include <iostream>
#include <string>

using namespace std;

int k;
string n;

int main() {
	cin >> k >> n;
	int sumn = 0;
	for(int i = 0; i < n.length(); ++i)
		sumn += n[i] - '0';

	if(sumn >= k) {
		cout << 0 << endl;
		return 0;
	}

	int freq[10] = {0};
	for(int i = 0; i < n.length(); ++i)
		++freq[n[i] - '0'];

	int res = 0;
	for(int i = 0; sumn < k && i < 10; ++i) {
		while(sumn < k && freq[i] > 0) {
			sumn += 9 - i;
			++res;
			--freq[i];
		}
	}

	cout << res << endl;

	return 0;
}
