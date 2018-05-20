#include <bits/stdc++.h>

using namespace std;

class Collision {
	double calc1(int sum, int ids) {
		if(sum > ids)
			return 0;
		
		double p = 1;
		for(int i = 1; i < sum; ++i)
			p *= 1.0 * (ids - i) / ids;
		return p;
	}
	
	double calc2(vector<int> assignments, int ids) {
		if(assignments[0] > ids)
			return 0;
		int sum = assignments[0];
		double p = 1;
		for(int i = 1; i < assignments.size(); ++i) {
			if(assignments[i] > ids)
				return 0;
			
			for(int j = 0; j < assignments[i]; ++j)
				p *= 1.0 * (ids - sum - j) / (ids - j);
			
			sum += assignments[i];
		}
		return p;
	}
	
public:
	double probability(vector<int> assignments, int ids) {
		int sum = 0;
		for(int i = 0; i < assignments.size(); ++i)
			sum += assignments[i];
		
		return calc2(assignments, ids) - calc1(sum, ids);
	}
};
