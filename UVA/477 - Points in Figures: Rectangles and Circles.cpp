#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct rect {
	double id, x1, y1, x2, y2;
};
vector<rect> rects;

struct circ {
	double id, x, y, rad;
};
vector<circ> circs;

vector<int> res;

int main() {
	char type;
	for(int i = 1; scanf(" %c", &type) && type != '*'; ++i)
		if(type == 'r') {
			rect r;
			r.id = i;
			scanf("%lf %lf %lf %lf", &r.x1, &r.y1, &r.x2, &r.y2);
			rects.push_back(r);
		} else if(type == 'c'){
			circ c;
			c.id = i;
			scanf("%lf %lf %lf", &c.x, &c.y, &c.rad);
			circs.push_back(c);
		}

	double x, y;
	for(int cnt = 1; scanf("%lf %lf", &x, &y) && x != 9999.9 && y != 9999.9; ++cnt) {
		res.clear();

		for(int i = 0; i < (int)rects.size(); ++i)
			if(rects[i].x1 <= x && rects[i].x2 >= x && rects[i].y1 >= y && rects[i].y2 <= y)
				res.push_back(rects[i].id);

		for(int i = 0; i < (int)circs.size(); ++i)
			if(((circs[i].x - x) * (circs[i].x - x)) + ((circs[i].y - y) * (circs[i].y - y)) <= circs[i].rad * circs[i].rad)
				res.push_back(circs[i].id);

		sort(res.begin(), res.end());
		if(res.empty())
			printf("Point %d is not contained in any figure\n", cnt);
		else
			for(int i = 0; i < (int)res.size(); ++i)
				printf("Point %d is contained in figure %d\n", cnt, res[i]);
	}

    return 0;
}

