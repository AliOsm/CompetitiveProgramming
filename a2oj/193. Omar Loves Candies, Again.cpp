#include <stdio.h>

using namespace std;

char s[101];

int main() {
  int t;
  scanf("%d", &t);
  
  while(t--) {
    scanf("%s", s);
    
    int freq[26] = {0};
    for(int i = 0; s[i] != '\0'; i++)
      freq[s[i] - 'a']++;
    
    int mxv = 0;
    char ch;
    for(int i = 0; i < 26; i++) {
      if(freq[i] > mxv) {
        mxv = freq[i];
        ch = char(i + 'a');
      }
    }
    
    printf("%d %c\n", mxv, ch);
  }
  
  return 0;
}

