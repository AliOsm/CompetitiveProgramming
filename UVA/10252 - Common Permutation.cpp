#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;
int frq1[26], frq2[26];

void print(char ch, int n) {
	for(int i = 0; i < n; ++i)
		cout << ch;
}

int main() {
	while(getline(cin, s1) && getline(cin, s2)) {
		memset(frq1, 0, sizeof frq1);
		for(int i = 0; i < (int)s1.length(); ++i)
			frq1[s1[i] - 'a']++;

		memset(frq2, 0, sizeof frq2);
		for(int i = 0; i < (int)s2.length(); ++i)
			frq2[s2[i] - 'a']++;

		for(int i = 0; i < 26; ++i)
			print(char(i + 'a'), min(frq1[i], frq2[i]));

		cout << endl;
	}
}

