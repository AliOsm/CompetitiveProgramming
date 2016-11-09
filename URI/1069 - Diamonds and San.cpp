#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> st;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int c = 0;
		string s;
		cin >> s;

		while (!st.empty()) st.pop();

		for (int i = 0, len = s.length(); i < len; i++) {
			if (s[i] == '<') {
				st.push(s[i]);
			}
			else if (s[i] == '>' && !st.empty() && st.top() == '<') {
				c++;
				st.pop();
			}
		}

		cout << c << endl;
	}

	return 0;
}
