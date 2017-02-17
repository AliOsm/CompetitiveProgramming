#include <stdio.h>

using namespace std;

int main() {
    int i;
    long l;
    long long ll;
    char c;
    float f;
    double d;
    
    scanf("%d %ld %lld %c %f %lf", &i, &l, &ll, &c, &f, &d);
    printf("%d\n%ld\n%lld\n%c\n%f\n%lf", i, l, ll, c, f, d);
    
    return 0;
}
