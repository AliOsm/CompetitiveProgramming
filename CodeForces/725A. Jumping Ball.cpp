#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, c = 0;
	string s;

	cin >> n >> s;

	if(s[0] != '>')
		for(int i = 0; i < n; i++)
			if(s[i] == '<') c++;
			else break;

	if(s[s.length() - 1] != '<')
		for(int i = n - 1; i >= 0; i--)
			if(s[i] == '>') c++;
			else break;

	cout << c << endl;

	return 0;
}
