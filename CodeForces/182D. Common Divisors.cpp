#include <iostream>
#include <string>

using namespace std;

int const N = 1e5 + 1;

void kmpWork(string &s, int f[]) {
  for (int i = 1, j = 0; i < s.length(); ++i) {
		while (j != 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) ++j;
		f[i] = j;
	}
}

int kmpSearch(string &t, string &p, int f[]) {
  int res = 0;
  for (int i = 0, j = 0; i < t.length(); ++i) {
		while (j != 0 && t[i] != p[j]) j = f[j - 1];
		if (t[i] == p[j]) ++j;
		if(j == p.length()) {
		  res++;
		  j = 0;
		}
	}
	return res;
}

int main() {
  int af[N], bf[N];
  
  string a, b;
  cin >> a >> b;
  
  kmpWork(a, af);
  kmpWork(b, bf);
  
  int resa = a.length();
  if(a.length() % (a.length() - af[a.length() - 1]) == 0)
    resa = a.length() - af[a.length() - 1];
  string suba = a.substr(0, resa);
  
  int resb = b.length();
  if(b.length() % (b.length() - bf[b.length() - 1]) == 0)
    resb = b.length() - bf[b.length() - 1];
  string subb = b.substr(0, resb);
  
  if(suba != subb)
    cout << 0 << endl;
  else {
    int res = 0, me = 1, i, j;
    bool ok;
    
    while(me * resa <= a.length() && me * resb <= b.length()) {
      if(a.length() % (me * resa) != 0 || b.length() % (me * resb) != 0) {
        me++;
        continue;
      }
      
      ok = true;
      
      for(i = 0, j = 0; i < a.length(); ++i, ++j) {
        if(a[i] != suba[j]) {
          ok = false;
          break;
        }
        
        if(j == resa - 1)
          j = -1;
      }
      
      if(!ok) {
        ++me;
        continue;
      }
      
      for(i = 0, j = 0; i < b.length(); ++i, ++j) {
        if(b[i] != subb[j]) {
          ok = false;
          break;
        }
        
        if(j == resb - 1)
          j = -1;
      }
      
      res += ok;
      me++;
    }
    
    cout << res << endl;
  }
  
  return 0;
}

