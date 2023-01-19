#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> both, first, second;

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0, t, a, b; i < n; ++i) {
        scanf("%d %d %d", &t, &a, &b);

        if(a + b == 2) {
            both.push_back(t);
        } else if(a == 1) {
            first.push_back(t);
        } else if(b == 1) {
            second.push_back(t);
        }
    }

    sort(both.begin(), both.end());
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int booksCount = 0;
    int totalReadingTime = 0;

    int j = 0, l = 0;

    for(int i = 0; i < both.size() && booksCount != k * 2;) {
        if(j < first.size() && l < second.size() && first[j] + second[l] < both[i]) {
            totalReadingTime += first[j] + second[l], ++j, ++l;
        } else {
            totalReadingTime += both[i], ++i;
        }

        booksCount += 2;
    }

    if(booksCount != k * 2) {
        int diff = ((k * 2) - booksCount) / 2, tmp = diff;
        
        while(j < first.size() && diff > 0) {
            totalReadingTime += first[j++];
            ++booksCount;
            --diff;
        }
        
        diff = tmp;

        while(l < second.size() && diff > 0) {
            totalReadingTime += second[l++];
            ++booksCount;
            --diff;
        }
    }

    if(booksCount != k * 2) {
        puts("-1");
    } else {
        printf("%d\n", totalReadingTime);
    }

    return 0;
}
