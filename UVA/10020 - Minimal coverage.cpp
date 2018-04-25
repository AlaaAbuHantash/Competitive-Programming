#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("test.txt", "rt", stdin);
	int t, r, x, y;
	scanf("%d", &t);
	bool f = 0;
	while (t--) {
		if (f)
			puts("");
		f = 1;
		vector<pair<int, int> > p;
		scanf("%d", &r);
		while (scanf("%d%d", &x, &y) > 0) {
			if (!x && !y)
				break;
			if (y < 0 || x > r)
				continue;
			p.push_back(mp(x, y));

		}
		sort(p.begin(), p.end());
		int n = p.size();
		int l = 0;
		int mx = -1, ind;
		vector<int> res;
		for (int i = 0; i < n; ++i) {
			if (l >= r)
				break;
			else if (p[i].first <= l) {
				if (p[i].second > mx) {
					ind = i, mx = p[i].second;
				}
			} else if (mx != -1) {
				res.push_back(ind);
				mx = -1;
				l = p[ind].second;
				i--;
			} else {
				res.clear();
				break;
			}
		}
		if (mx != -1) {
			res.push_back(ind);
			l = p[ind].second;
		}

		int rr = res.size();
		if(l<r)
			rr=0;
		printf("%d\n", rr);
		if (rr && l>=r)
			for (int i = 0; i < rr; ++i){
				printf("%d %d\n", p[res[i]].first, p[res[i]].second);
			}

	}
	return 0;
}

