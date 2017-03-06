#include <iostream>
#include <set>

using namespace std;

int const N = 1e5 + 1;
int arr[N], cum[N];
set<int> st;

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = n - 1; i >= 0; i--) {
        st.insert(arr[i]);
        cum[i] = st.size();
    }
    
    int tmp;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        cout << cum[tmp - 1] << endl;
    }
    
    return 0;
}
