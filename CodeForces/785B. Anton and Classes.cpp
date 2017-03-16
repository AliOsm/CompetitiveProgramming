#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int> > chess, prog;
int n, m;
int bchess = 0, echess = 1e9 + 10, bprog = 0, eprog = 1e9 + 10;

int main() {
  int a, b;

  cin >> n;
  while(n--) {
    cin >> a >> b;
    chess.push_back(make_pair(a, b));
  }
  n = chess.size();

  cin >> m;
  while(m--) {
    cin >> a >> b;
    prog.push_back(make_pair(a, b));
  }
  m = prog.size();

  for(int i = 0; i < n; i++) {
    if(bchess <= chess[i].first)
      bchess = chess[i].first;

    if(echess >= chess[i].second)
      echess = chess[i].second;
  }

  for(int i = 0; i < m; i++) {
    if(bprog <= prog[i].first)
      bprog = prog[i].first;

    if(eprog >= prog[i].second)
      eprog = prog[i].second;
  }

  if(bprog - echess > 0 || bchess - eprog > 0)
    cout << max(bprog - echess, bchess - eprog) << endl;
  else
    cout << 0 << endl;

  return 0;
}

