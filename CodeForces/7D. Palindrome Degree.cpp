/*
  Idea:
    - Using hashing we can check for each prefix if it is
      a palindrome or not.
    - From the information from the previous point we can
      calculate the result.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 5e6 + 1;
int const p = 67;
int const m = 1e9 + 9;
char s[N];
int n, res[N];
long long hash_value[N][2];
long long p_pow[N];

long long compute_hash() {
  p_pow[0] = 1;
  for(int i = 1; i < N; ++i)
    p_pow[i] = (p_pow[i - 1] * p) % m;

  if(islower(s[0]))
    hash_value[0][0] = ((s[0] - 'a' + 1) * p_pow[0]) % m;
  else if(isupper(s[0]))
    hash_value[0][0] = ((s[0] - 'A' + 27) * p_pow[0]) % m;
  else
    hash_value[0][0] = ((s[0] - '0' + 53) * p_pow[0]) % m;

  for(int i = 1; i < n; ++i) {
    if(islower(s[i]))
      hash_value[i][0] = (hash_value[i - 1][0] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    else if(isupper(s[i]))
      hash_value[i][0] = (hash_value[i - 1][0] + (s[i] - 'A' + 27) * p_pow[i]) % m;
    else
      hash_value[i][0] = (hash_value[i - 1][0] + (s[i] - '0' + 53) * p_pow[i]) % m;
  }

  if(islower(s[n - 1]))
    hash_value[n - 1][1] = ((s[n - 1] - 'a' + 1) * p_pow[0]) % m;
  else if(isupper(s[n - 1]))
    hash_value[n - 1][1] = ((s[n - 1] - 'A' + 27) * p_pow[0]) % m;
  else
    hash_value[n - 1][1] = ((s[n - 1] - '0' + 53) * p_pow[0]) % m;

  for(int i = n - 2; i >= 0; --i) {
    if(islower(s[i]))
      hash_value[i][1] = (hash_value[i + 1][1] + (s[i] - 'a' + 1) * p_pow[n - i - 1]) % m;
    else if(isupper(s[i]))
      hash_value[i][1] = (hash_value[i + 1][1] + (s[i] - 'A' + 27) * p_pow[n - i - 1]) % m;
    else
      hash_value[i][1] = (hash_value[i + 1][1] + (s[i] - '0' + 53) * p_pow[n - i - 1]) % m;
  }
}

bool is_pal(int idx) {
  long long first_hash = hash_value[idx][0];
  long long second_hash = (hash_value[0][1] - hash_value[idx + 1][1] + m) % m;

  first_hash = (first_hash * p_pow[(n - idx - 1)]) % m;

  return first_hash == second_hash;
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  compute_hash();

  res[0] = 1;
  for(int i = 1; i < n; ++i)
    if(is_pal(i))
      res[i] = res[i / 2 - !(i & 1)] + 1;

  int to = 0;
  for(int i = 0; i < n; ++i)
    to += res[i];
  
  printf("%d\n", to);

  return 0;
}
