/*
	Idea:
		- Greedy.
		- For each student try to give him/her 300 points and imagine that all other
			students did not solve any problem and count the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[16];

int main() {
    for(int i = 0; i < 16; ++i)
        cin >> a[i];
    reverse(a, a + n);
    
    int res = 0;
    for(int i = 0; i < 16; ++i) {
        a[i] += 300;
        int cnt = 1;
        for(int j = 0; j < 16; ++j)
            if(i != j && a[i] > a[j])
                ++cnt;
        if(cnt > 12)
            ++res;
        a[i] -= 300;
    }
    
    cout << res << endl;
    
    return 0;
}
