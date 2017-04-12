#include <stdio.h>

using namespace std;

int arr[101], sol[101];

int main() {
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  
  for(int i = 0; i < n; i++)
    sol[arr[i] - 1] = i + 1;
  
  for(int i = 0; i < n; i++) {
    if(i) putchar(' ');
    printf("%d", sol[i]);
  }
  putchar('\n');
  
  return 0;
}

