/*
	Idea:
		- Using Dynamic programming we can try all possible grids and save
			the state of winning or losing for each one of them.
		- For each query we can build a mask for the grid and check if its
			state is winning or losing.
*/

#include <bits/stdc++.h>

using namespace std;

int t, msk, dp[(1 << 16)];
char s[5][5];

inline int get(int i, int j) {
	return i * 4 + j;
}

int rec(int msk) {
	if(msk == (1 << 16) - 1)
		return 1;
	
	int &ret = dp[msk];
	if(ret != -1)
		return ret;
	ret = 0;

	// pin size 1
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) {
			if((msk & (1 << get(3 - i, 3 - j))) != 0)
				continue;
			ret |= !rec(msk | (1 << get(3 - i, 3 - j)));
		}

	// pin size 2
	for(int i = 0; i < 4; ++i) {
		// fill rows
		if((msk & (1 << get(3 - i, 3))) == 0 && (msk & (1 << get(3 - i, 2))) == 0)
			ret |= !rec(msk | (1 << get(3 - i, 3)) | (1 << get(3 - i, 2)));
		if((msk & (1 << get(3 - i, 1))) == 0 && (msk & (1 << get(3 - i, 0))) == 0)
			ret |= !rec(msk | (1 << get(3 - i, 1)) | (1 << get(3 - i, 0)));

		// fill columns
		if((msk & (1 << get(3, 3 - i))) == 0 && (msk & (1 << get(2, 3 - i))) == 0)
			ret |= !rec(msk | (1 << get(3, 3 - i)) | (1 << get(2, 3 - i)));
		if((msk & (1 << get(1, 3 - i))) == 0 && (msk & (1 << get(0, 3 - i))) == 0)
			ret |= !rec(msk | (1 << get(1, 3 - i)) | (1 << get(0, 3 - i)));
	}

	// pin size 3
	for(int i = 0; i < 4; ++i) {
		// fill rows
		if((msk & (1 << get(3 - i, 3))) == 0 && (msk & (1 << get(3 - i, 2))) == 0 && (msk & (1 << get(3 - i, 1))) == 0)
			ret |= !rec(msk | (1 << get(3 - i, 3)) | (1 << get(3 - i, 2)) | (1 << get(3 - i, 1)));
		if((msk & (1 << get(3 - i, 2))) == 0 && (msk & (1 << get(3 - i, 1))) == 0 && (msk & (1 << get(3 - i, 0))) == 0)
			ret |= !rec(msk | (1 << get(3 - i, 2)) | (1 << get(3 - i, 1)) | (1 << get(3 - i, 0)));

		// fill columns
		if((msk & (1 << get(3, 3 - i))) == 0 && (msk & (1 << get(2, 3 - i))) == 0 && (msk & (1 << get(1, 3 - i))) == 0)
			ret |= !rec(msk | (1 << get(3, 3 - i)) | (1 << get(2, 3 - i)) | (1 << get(1, 3 - i)));
		if((msk & (1 << get(2, 3 - i))) == 0 && (msk & (1 << get(1, 3 - i))) == 0 && (msk & (1 << get(0, 3 - i))) == 0)
			ret |= !rec(msk | (1 << get(2, 3 - i)) | (1 << get(1, 3 - i)) | (1 << get(0, 3 - i)));
	}

	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	rec(msk);

	scanf("%d", &t);
	while(t-- != 0) {
		msk = 0;
		for(int i = 0; i < 4; ++i)
			scanf("%s", s[i]);
		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				if(s[i][j] == 'X')
					msk |= (1 << get(3 - i, 3 - j));
		if(dp[msk])
			puts("WINNING");
		else
			puts("LOSING");
	}

	return 0;
}
