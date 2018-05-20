/*
	idea:
		- we need to calculate the first and the second probability then subtract them.
		- for the first probability (without memory) we need to sum all assignments from
			all components then calculate the probability of assign two ids to the same client
		  to do that, for the first client the probability it 100% that there is no collision
		  and for each client i (0 < i < sum) the probability is ((ids - i) / ids), because
		  each time we assign an id to a client we lose an id from the pool of unique ids.
		- for the second probability (with memory) we know that the probability for the first
			component (comp[0]) it is either 0 if the number of assignments bigger than the
		  number of ids or 1 otherwise, then for the second component the probability of
			assign the first id without collision is ((ids - comp[0]) / ids) and for the second
			assignment the probability is ((ids - comp[0] - 1) / (ids - 1), so in general for the
			ith assignment in the second component the probability is ((ids - comp[0] - i) / (ids - i))
			and so on for the remaining components.
*/

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
