#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	for (int i = 0; i < s1.length(); i++) {
		if (s3.find(s1[i]) != string::npos) {
			s3.erase(s3.find(s1[i]), 1);
			s1.erase(i, 1);
			i--;
		}
	}

	for (int i = 0; i < s2.length(); i++) {
		if (s3.find(s2[i]) != string::npos) {
			s3.erase(s3.find(s2[i]), 1);
			s2.erase(i, 1);
			i--;
		}
	}

	if (s3.empty() && s1.empty() && s2.empty()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}
