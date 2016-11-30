#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<vector<int> > g;
vector<int> sol;
map<int, int> in;
queue<int> q;
int n, m;

int main() {
    int a, b;
    
    while(true) {
        scanf("%i %i", &n, &m);
        if(!n) break;
        
        in.clear();
        sol.clear();
        g.clear();
        g.resize(n);
        
        for(int i = 0; i < m; i++) {
            scanf("%i %i", &a, &b);
            a--; b--;
            g[a].push_back(b);
            in[b]++;
        }
        
        for(int i = 0; i < n; i++)
            if(in[i] == 0)
                q.push(i);
                
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            sol.push_back(fr + 1);
            
            for(int i = 0; i < g[fr].size(); i++)
                if(--in[g[fr][i]] == 0)
                    q.push(g[fr][i]);
        }

        for(int i = 0; i < sol.size(); i++) {
            printf("%i", sol[i]);
            if(i < sol.size() - 1) putchar(' ');
        }
        
        putchar('\n');
    }
    
    return 0;
}
