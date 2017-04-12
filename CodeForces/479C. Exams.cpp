#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > exams;

int main() {
  int n;
  scanf("%d", &n);
  
  exams.resize(n);
  
  for(int i = 0; i < n; i++)
    scanf("%d%d", &exams[i].first, &exams[i].second);
  sort(exams.begin(), exams.end());
  
  int cur = 0, lst = 0;
  for(int i = 0; i < n; i++) {
    if(exams[i].first >= cur && exams[i].second >= lst) {
      cur = exams[i].first;
      lst = exams[i].second;
    } else
      cur = lst = exams[i].first;
  }
  
  printf("%d\n", lst);
  
  return 0;
}

