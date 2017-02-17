#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<pair<int, string> > st;

int main() {
    int q, tmp;
    string s = "", a;
    
    cin >> q;
    
    while(q--) {
        cin >> tmp;
        
        switch(tmp) {
            case 1:
                cin >> a;
                s += a;
                st.push(make_pair(1, a));
                break;
            case 2:
                cin >> tmp;
                st.push(make_pair(2, s.substr(s.length() - tmp)));
                s = s.substr(0, s.length() - tmp);
                break;
            case 3:
                cin >> tmp;
                cout << s[tmp-1] << endl;
                break;
            case 4:
                pair<int, string> ptmp = st.top();
                st.pop();
                
                if(ptmp.first == 1)
                    s = s.substr(0, s.length() - ptmp.second.length());
                else
                    s += ptmp.second;
                
                break;
        }
    }
    
    return 0;
}
