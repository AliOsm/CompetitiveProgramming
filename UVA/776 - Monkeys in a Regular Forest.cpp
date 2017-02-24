#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <memory.h>

using namespace std;

int const N = 101;
int n, m, cnt;
int vis[N][N];
vector<string> g;
vector<int> printRes;
void DFS(int, int);
int getDigits(int);
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
    string tmp;
    char c = ' ';

    while((c = getchar()) != EOF) {
        memset(vis, 0, sizeof vis);
        g.clear();
        printRes.clear();
        cnt = 0;

        while(c != EOF) {
            tmp = "";

            do {
                if(c != ' ' && c != '\n')
                    tmp += c;
            } while((c = getchar()) != EOF && c != '\n' && c != '%');

            if(tmp != "")
                g.push_back(tmp);

            if(c == '%')
                break;
        }

        n = g.size();
        m = g[0].length();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j]) {
                    cnt++;
                    DFS(i, j);
                }

        int mx = 0;
        for(int i = 0; i < m; i++) {
            mx = 0;
            for(int j = 0; j < n; j++)
                if(vis[j][i] > mx)
                    mx = vis[j][i];

            printRes.push_back(getDigits(mx));
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%*d", printRes[j], vis[i][j]);

                if(j + 1 < m)
                    putchar(' ');
            }

            putchar('\n');
        }

        puts("%");
    }

    return 0;
}

void DFS(int i, int j) {
    vis[i][j] = cnt;

    int nx, ny;

    for(int k = 0; k < 8; k++) {
        nx = i + dx[k];
        ny = j + dy[k];

        if(nx < n && nx >= 0 && ny < m && ny >= 0 && !vis[nx][ny] && g[i][j] == g[nx][ny])
            DFS(nx, ny);
    }
}

int getDigits(int n) {
    int tmp = 0;

    while(n) {
        tmp++;
        n /= 10;
    }

    return tmp;
}
