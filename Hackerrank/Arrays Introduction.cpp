#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;

	cin >> x;

    vector<int> arr(x);
    
    for(int i = 1; i <= x; i++)
        cin >> arr[i];
    
    for(int i = x; i >= 1; i--)
        cout << arr[i] << " ";

    return 0;
}
