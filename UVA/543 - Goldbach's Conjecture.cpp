#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 3 * 1e6 + 1;
bool bPrime[N];
vector<int> iPrime;

void sieve() {
  for (int p = 2; p <= N; p++)
    if (bPrime[p] == false) {
      iPrime.push_back(p);
      for (int i = p * 2; i <= N; i += p)
        bPrime[i] = true;
    }
}

int main() {
	bPrime[0] = true;
  bPrime[1] = true;
  sieve();

  int n;
	bool is_here;
    
	while(cin >> n && n) {
		is_here = false;

		for(int i = 0; i < iPrime.size() && iPrime[i] < n; i++)
			if(binary_search(iPrime.begin(), iPrime.end(), n - iPrime[i])) {
				is_here = true;
				cout << n << " = " << iPrime[i] << " + " << n - iPrime[i] << endl;
				break;
			}

		if(!is_here)
			cout << "Goldbach's conjecture is wrong." << endl;
	}

	return 0;
}
