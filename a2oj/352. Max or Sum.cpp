#include <iostream>

using namespace std;

int main() {
    int a, b, c, max, min, mid;

    cin >> a >> b >> c;

    if(a >= b && a >= c) {
        max = a;
    } else if(b >= a && b >= c) {
        max = b;
    } else if(c >= b && c >= a) {
        max = c;
    }

    if(a <= b && a <= c) {
        min = a;
    } else if(b <= a && b <= c) {
        min = b;
    } else if(c <= b && c <= a) {
        min = c;
    }

    if(a == max && b == min) {
        mid = c;
    } else if(b == max && a == min) {
        mid = c;
    } else if(a == max && c == min) {
        mid = b;
    } else if(c == max && a == min) {
        mid = b;
    } else if(b == max && c == min) {
        mid = a;
    } else if(c == max && b == min) {
        mid = a;
    }

    if(min + mid > max){
        cout << min + mid;
    } else {
        cout << max;
    }

    return 0;
}
