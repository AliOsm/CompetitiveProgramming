#include <stdio.h>
#include <string.h>
#include <algorithm>

int main() {
    int t, len;
    scanf("%i", &t);

    char s[10];

    while(t--) {
        scanf("%s", s);
        len = strlen(s);

        std::sort(s, s+len);

        do
            printf("%s\n", s);
        while(std::next_permutation(s, s+len));
        
        puts("");
    }

    return 0;
}
