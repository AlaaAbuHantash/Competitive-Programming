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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int t, tt = 1, n, x, d;
vector<pair<int, pair<int, int> > > p;
vector<int> parent;
int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

int main() {

	//freopen("A.txt", "r", stdin);
	//freopen ("myfile.txt","w",stdout);

	scanf("%d", &t);
	while (t--) {
		p.clear();
		scanf("%d", &n);
		parent.clear();
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d,", &d);
				if (d)
					p.push_back(mp(d, mp(i, j)));
			}
			parent[i] = i;
		}
		sort(p.begin(), p.end());
		int len = p.size();
		printf("Case %d:\n", tt++);

		for (int i = 0; i < len; i++) {
			//cout << p[i].second.second << " " << p[i].second.first << " "
				//	<< p[i].first << endl;
			if (find(p[i].second.first) != find(p[i].second.second)) {
				parent[find(p[i].second.first)] = find(p[i].second.second);
				printf("%c-%c %d\n", char(p[i].second.first + 'A'),
						char(p[i].second.second + 'A'), p[i].first);
			}
		}
	}
	return 0;

}


