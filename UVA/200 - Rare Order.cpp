#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector<vector<int> > g(26);
vector<string> words;
bool vis[26];
string sol;

void DFS(int node) {
	vis[node] = true;
	
	for(int i = 0; i < (int)g[node].size(); i++)
		if(!vis[g[node][i]])
			DFS(g[node][i]);
	
	sol += char(node + 'A');
}

int main() {
	string s;
    
    while(cin >> s && s != "#")
        words.push_back(s);
      
    if(words.size() == 1) {
        cout << words[0] << endl;
        return 0;
    }
    
    for(int i = 0; i < words.size() - 1; i++) {
        int j;
		for(j = 0; words[i][j] == words[i+1][j] && j < words[i].length() && j < words[i+1].length(); j++);
		
		if(words[i][j] != words[i+1][j])
			g[words[i][j] - 'A'].push_back(words[i+1][j] - 'A');
    }
    
    sol = "";
        
    for(int i = 0; i < 26; i++)
		if(!vis[i] && g[i].size())
			DFS(i);
	
	reverse(sol.begin(), sol.end());
	cout << sol << endl;
   
   return 0;
}
