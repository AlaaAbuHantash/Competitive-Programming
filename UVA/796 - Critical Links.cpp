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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, nod, k, x, root, cnt;
vector<vector<int> > v;
vector<int> num, low, parent;
vector<pair<int, int> > p;
void calc(int x) {
	//cout << "x  x " << x << endl;
	low[x] = num[x] = cnt++;
	for (int j = 0; j < v[x].size(); j++)
		if (!num[v[x][j]]) {
			parent[v[x][j]] = x;
			calc(v[x][j]);
			if (low[v[x][j]] > num[x])
				p.push_back(mp(min(x,v[x][j]),max(x, v[x][j])));
			low[x] = min(low[x], low[v[x][j]]);
		} else if (v[x][j] != parent[x]){
			low[x] = min(low[x], num[v[x][j]]);
			//cout << x << " " << low[x]  << " " << v[x][j]<< endl;
		}
}
int main() {
//freopen("A.txt" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);

	while (scanf("%d", &n) > 0) {
		v.clear();
		v.resize(n);
		num.clear();
		num.resize(n);
		low.clear();
		low.resize(n);
		parent.clear();
		parent.resize(n);
		p.clear();
		char cc;

		for (int i = 0; i < n; i++) {
			scanf("%d %c %d %c", &nod, &cc, &k, &cc);

			for (int j = 0; j < k; j++) {
				scanf("%d", &x);
				v[nod].push_back(x);
				//v[x].push_back(nod);
			}
		}
		cnt = 1;
		for (int i = 0; i < n; i++) {
			if (!num[i]) {
				root = i;
				calc(i);
			}
		}

		sort(p.begin(), p.end());
		printf("%d critical links\n",p.size());
		for (int i = 0; i < p.size(); i++)
			printf("%d - %d\n", p[i].first, p[i].second);
		puts("");
	}

	return 0;
}


