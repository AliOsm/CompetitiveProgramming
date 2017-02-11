#include <iostream>
#include <set>
 
using namespace std;
 
set<int> st;
 
int main() {
	int n, m, res, tmp;
 
	while(cin >> n >> m && n && m) {
	    st.clear();
	    res = 0;
 
	    while(n--) {
	        cin >> tmp;
	        st.insert(tmp);
	    }
 
	    while(m--) {
	        cin >> tmp;
	        if(st.count(tmp)) res++;
	    }
 
	    cout << res << endl;
	}
 
	return 0;
}
