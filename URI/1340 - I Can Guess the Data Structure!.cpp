#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > arr;
stack<int> st;
queue<int> q;
priority_queue<int> pq;

int main() {
	int n;
	
	while (cin >> n) {
		arr.clear();
		while(!st.empty()) st.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
		
		bool is_stack = true, is_queue = true, is_priority_queue = true;
		
		while(n--) {
			int t1, t2;
			cin >> t1 >> t2;
			arr.push_back(make_pair(t1, t2));
		}
		n = arr.size();
		
		for(int i = 0; i < n; i++) {
			int t1, t2;
			t1 = arr[i].first;
			t2 = arr[i].second;
			
			if(t1 == 1)
				st.push(t2);
			else {
				if(t2 == st.top())
					st.pop();
				else {
					is_stack = false;
					break;
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			int t1, t2;
			t1 = arr[i].first;
			t2 = arr[i].second;
			
			if(t1 == 1)
				q.push(t2);
			else {
				if(t2 == q.front())
					q.pop();
				else {
					is_queue = false;
					break;
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			int t1, t2;
			t1 = arr[i].first;
			t2 = arr[i].second;
			
			if(t1 == 1)
				pq.push(t2);
			else {
				if(t2 == pq.top())
					pq.pop();
				else {
					is_priority_queue = false;
					break;
				}
			}
		}
		
		if(!is_stack && !is_queue && !is_priority_queue)
			cout << "impossible" << endl;
		else if((is_stack && is_queue) || (is_queue && is_priority_queue) || (is_priority_queue && is_stack))
			cout << "not sure" << endl;
		else
			if(is_stack)
				cout << "stack" << endl;
			else if(is_queue)
				cout << "queue" << endl;
			else if(is_priority_queue)
				cout << "priority queue" << endl;
	}

	return 0;
}
