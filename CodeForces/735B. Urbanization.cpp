#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int const N = 100001;
int arr[N];

bool cmp(int a, int b) {
	  return a > b;
}

int main() {
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    if(n1 > n2) swap(n1, n2);
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1, arr+n+1, cmp);
    
    double t = 0;
    long long tmp;
    
    tmp = 0;
    for(int i = 1; i <= n1; i++) tmp += arr[i];
    t += (1.0 * tmp / n1);

    tmp = 0;
    for(int i = n1 + 1; i <= n1 + n2; i++) tmp += arr[i];
    t += (1.0 * tmp / n2);
    
    cout << fixed << setprecision(8) << t << endl;
}
