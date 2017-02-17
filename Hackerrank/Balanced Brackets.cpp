#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> st;

int main(){
    int t, i;
    cin >> t;
    
    string s;
    while(t--) {
        while(!st.empty()) st.pop();
        cin >> s;

        for(i = 0; i < s.length(); i++)
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else if(!st.empty() && st.top() == '(' && s[i] == ')') st.pop();
            else if(!st.empty() && st.top() == '{' && s[i] == '}') st.pop();
            else if(!st.empty() && st.top() == '[' && s[i] == ']') st.pop();
            else {
                cout << "NO" << endl;
                break;
            }
        
        if(i == s.length())
            if(st.size() == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
    }
    
    return 0;
}
