#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
    int n, tmp;
    cin >> n;
    
    while(n--) {
        cin >> tmp;
        
        switch(tmp) {
            case 1:
            cin >> tmp;
            q.push(tmp);
            break;
            case 2:
            q.pop();
            break;
            default:
            cout << q.front() << endl;
        }
    }
    
    return 0;
}
