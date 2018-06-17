/*
	Idea:
		- Using Dynamic programming, we can play the game in a recursive
			function and store the result for each state.
*/

#include <bits/stdc++.h>

using namespace std;

char s[25];
int rem[6], dp[32][5][5][5][5][5][5];

bool rec(int sum) {
	if(sum > 31)
		return true;

	int &ret = dp[sum][rem[0]][rem[1]][rem[2]][rem[3]][rem[4]][rem[5]];
	if(ret != -1)
		return ret;
	ret = false;

	for(int i = 0; i < 6; ++i)
		if(rem[i] != 0) {
			--rem[i];
			ret |= !rec(sum + i + 1);
			++rem[i];
		}

	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	while(scanf("%s", s) != EOF) {
		for(int i = 0; i < 6; ++i)
			rem[i] = 4;
		int sum = 0, len = strlen(s);
		for(int i = 0; i < len; ++i) {
			sum += (s[i] - '0');
			--rem[s[i] - '1'];
		}

		if(len & 1) {
			if(rec(sum))
				printf("%s B\n", s);
			else
				printf("%s A\n", s);
		} else {
			if(rec(sum))
				printf("%s A\n", s);
			else
				printf("%s B\n", s);
		}
	}

	return 0;
}
