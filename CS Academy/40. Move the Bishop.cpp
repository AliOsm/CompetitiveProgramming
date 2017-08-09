#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    if(x1 == x2 && y1 == y2) {
        puts("0");
        return 0;
    }
    
    if(abs(x1 - x2) == abs(y1 - y2)) {
        puts("1");
        return 0;
    }
    
    for(int i = x1 + 1, j = y1 + 1; i <= 8 && j <= 8; ++i, ++j)
        if(abs(i - x2) == abs(j - y2)) {
            puts("2");
            return 0;
        }
    for(int i = x1 + 1, j = y1 - 1; i <= 8 && j >= 0; ++i, --j)
        if(abs(i - x2) == abs(j - y2)) {
            puts("2");
            return 0;
        }
    for(int i = x1 - 1, j = y1 + 1; i >= 0 && j <= 8; --i, ++j)
        if(abs(i - x2) == abs(j - y2)) {
            puts("2");
            return 0;
        }
    for(int i = x1 - 1, j = y1 - 1; i >= 0 && j >= 0; --i, --j)
        if(abs(i - x2) == abs(j - y2)) {
            puts("2");
            return 0;
        }
    
    puts("-1");
    
    return 0;
}
