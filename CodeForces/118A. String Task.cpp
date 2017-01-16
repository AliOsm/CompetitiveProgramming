#include <iostream>
#include <string>

using namespace std;

string lower(string s) {
	int  x = s.length();

	for (int i = 0; i < x; i++)
		s[i] = tolower(s[i]);

	return s;
}

string removeVowels(string s1) {
	string s2 = "";

	for (int i = 0; i < s1.length(); i++)
		if (s1[i] != 'a' && s1[i] != 'o' && s1[i] != 'y' && s1[i] != 'e' && s1[i] != 'u' && s1[i] != 'i')
			s2 += s1[i];

	return s2;
}

string addPoint(string s1) {
	string s2 = "";

	for (int i = 0; i < s1.length(); i++)
		s2 = s2 + "." + s1[i];
	
	return s2;
}

int main() {
	string s;

	cin >> s;

	s = lower(s);
	s = removeVowels(s);
	s = addPoint(s);

	cout << s << endl;

	return 0;
}
