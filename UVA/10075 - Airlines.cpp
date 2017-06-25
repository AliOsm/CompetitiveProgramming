#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

typedef long long ll;

using namespace std;

#define earthRadiusKm 6378.0
#define PI 3.141592653589793

double deg2rad(double deg) {
  return (deg * PI / 180);
}

double rad2deg(double rad) {
  return (rad * 180 / PI);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

struct city {
	string name;
	double ltt, lng;

	city(string name, double ltt, double lng) :
		name(name), ltt(ltt), lng(lng) {}
};

long long const OO = 2e9, N = 101;
int n, m, q;
long long floyd[N][N];
vector<city> cities;
map<string, int> name_to_id;

int main() {
	string name, from, to;
	int a, b;
	double ltt, lng;
	bool blankline = false;
	for(int cnt = 1; scanf("%d%d%d", &n, &m, &q) && n != 0 && m != 0 && q != 0; ++cnt) {
		if(blankline)
			puts("");

		name_to_id.clear();
		cities.clear();
		for(int i = 0; i < n; ++i) {
			cin >> name;
			scanf("%lf%lf", &ltt, &lng);
			cities.push_back(city(name, ltt, lng));
			name_to_id[name] = i;
		}

		for(int i = 0; i < N; i++) {
			fill(floyd[i], floyd[i] + N, OO);
			floyd[i][i] = 0;
		}

		for(int i = 0; i < m; ++i) {
			cin >> from >> to;
			a = name_to_id[from];
			b = name_to_id[to];

			floyd[a][b] = round(distanceEarth(cities[a].ltt, cities[a].lng,
					   	   	   	   	    	  cities[b].ltt, cities[b].lng));
		}

		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

		printf("Case #%d\n", cnt);

		for(int i = 0; i < q; ++i) {
			cin >> from >> to;
			a = name_to_id[from];
			b = name_to_id[to];

			if(floyd[a][b] == OO)
				puts("no route exists");
			else
				printf("%lld km\n", floyd[a][b]);
		}

		blankline = true;
	}

	return 0;
}

