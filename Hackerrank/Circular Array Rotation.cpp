#include <iostream>

using namespace std;

int const N = 1e5;
int arr[N + 1];

int main(){
    int n, k, q;
    cin >> n >> k >> q;

    k = k % n;

    for(int i = k; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < k; i++)
        cin >> arr[i];

    for(int a0 = 0; a0 < q; a0++){
        int m;
        cin >> m;
        cout << arr[m] << endl;
    }
    
    return 0;
}
