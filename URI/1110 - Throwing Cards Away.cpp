#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
    int n;
    
    while(true) {
    	cin >> n;
    	if(n == 0) break;
    	
    	while(!q.empty()) q.pop();
    	for(int i = 1; i <= n; i++) q.push(i);
    	
    	cout << "Discarded cards: ";
    	while(q.size() != 1) {
    		int tmp;
    		
    		tmp = q.front();
    		q.pop();
    		
    		cout << tmp;
    		if(q.size() != 1) cout << ", ";
    		
    		tmp = q.front();
    		q.pop();
    		q.push(tmp);
    	}
    	
    	cout << endl;
    	cout << "Remaining card: " << q.front() << endl;
    }
    
    return 0;
}
