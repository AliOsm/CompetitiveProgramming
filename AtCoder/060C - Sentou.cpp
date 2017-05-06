#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> a;
     
int main() {
    long long n, t;
    scanf("%llu%llu", &n, &t);
    a.resize(n);
    for(int i = 0; i < n; ++i)
        scanf("%llu", &a[i]);
    	
    long long res = t;
    for(int i = 1; i < n; ++i) {
        if(a[i] - a[i-1] <= t)
            res += (a[i] - a[i-1]);
        else
	    res += t;
    }
    	
    printf("%lld\n", res);
     
    return 0;
}
