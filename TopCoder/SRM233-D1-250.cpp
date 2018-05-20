/*
	idea:
		- We can do a brute force and counting the number of all possibilities and
			the number of possibilities when there is a pipe with length more than L
			then return the division result.
*/

#include <bits/stdc++.h>

using namespace std;

class PipeCuts {
public:
	double probability(vector<int> weldLocations, int L) {
		sort(weldLocations.begin(), weldLocations.end());
		int all = 0, cnt = 0;
		for(int i = 0; i < weldLocations.size(); ++i) {
			for(int j = i + 1; j < weldLocations.size(); ++j) {
				++all;
				int c1 = weldLocations[i], c2 = weldLocations[j] - weldLocations[i], c3 = 100 - weldLocations[j];
				
				if(c1 > L || c2 > L || c3 > L)
					++cnt;
			}
		}
		return 1.0 * cnt / all;
	}
};