#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
stack<int> mx;

int main() {
    int n, v, tmp;
    cin >> n;
    
    mx.push(0);
    
    while(n--) {
        cin >> tmp;
        
        if(tmp == 1) {
            cin >> v;
            st.push(v);
            if(v >= mx.top()) mx.push(v);
        } else if(tmp == 2) {
            if(st.top() == mx.top()) mx.pop();
            st.pop();
        } else
            cout << mx.top() << endl;
    }
    
    return 0;
}
