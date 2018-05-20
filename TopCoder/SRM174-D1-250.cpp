#include <bits/stdc++.h>

using namespace std;

class BirthdayOdds {
public:
	int minPeople(int minOdds, int DaysInYear) {
		double comp = 100 - minOdds;
		double all = 100;
		for(int i = DaysInYear - 1; i >= 0; --i) {
			if(all <= comp)
				return DaysInYear - i;
			all *= (1.0 * i / DaysInYear);
		}
		return DaysInYear + 1;
	}
};
