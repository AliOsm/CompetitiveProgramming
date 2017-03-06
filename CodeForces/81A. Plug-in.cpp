#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> st;

int main() {
    string s;
    cin >> s;
    
    for(int i = 0; i < s.length(); i++)
        if(!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    
    s = "";
    while(!st.empty()) {
        s += st.top();
        st.pop();
    }
    
    for(int i = s.length() - 1; i >= 0; i--)
        cout << s[i];
    cout << endl;
    
    return 0;
}
