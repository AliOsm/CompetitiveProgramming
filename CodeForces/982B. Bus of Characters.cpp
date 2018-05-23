/*
	Idea:
		- Greedy.
		- Sort the given array.
		- In each step if the current person is introvert then put it in the first
			unoccupied seat.
		- In each step if the current person is extrovert then put it in the first
			occupied seat.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, p;
pair<int, int> a[N];
string s;
stack<int> st;

int main() {
 	cin >> n;
 	for(int i = 0; i < n; ++i) {
 		cin >> a[i].first;
 		a[i].second = i + 1;
 	}
 	cin >> s;
 	sort(a, a + n);

 	for(int i = 0; i < s.length(); ++i)
 		if(s[i] == '0') {
 			cout << a[p].second << ' ';
 			st.push(a[p].second);
 			++p;
 		} else {
 			cout << st.top() << ' ';
 			st.pop();
 		}
 	cout << endl;

  return 0;
}
