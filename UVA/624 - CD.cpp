#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

int sum, tmpSum;
vector<int> res, tmpRes;

void trY(int index) {
  if(index == m) {
    if(tmpSum > sum) {
      sum = tmpSum;
      res = tmpRes;
    }
    
    return;
  }
  
  trY(index + 1);
  
  tmpSum += arr[index];
  
  if(tmpSum > n) {
    tmpSum -= arr[index];
    return;
  }
  
  tmpRes.push_back(arr[index]);
  trY(index + 1);
  tmpSum -= arr[index];
  tmpRes.pop_back();
}

int main() {
  while(scanf("%d%d", &n, &m) != EOF) {
    arr.clear();
    arr.resize(m);
    for(int i = 0; i < m; ++i)
      scanf("%d", &arr[i]);
    
    sum = tmpSum = 0;
    res.clear();
    tmpRes.clear();
    trY(0);
    
    for(int i = 0; i < res.size(); ++i)
      printf("%s%d", (i ? " " : ""), res[i]);
    printf(" sum:%d", sum);
    putchar('\n');
  }
  
  return 0;
}

