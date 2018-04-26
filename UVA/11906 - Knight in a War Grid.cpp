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
int n, m, x, y, k, a, b;
int vis[111][111];
int vis2[111][111];
int odd, even;
set<pair<int, int> > st;
vector<pair<int, int> > d;
set<pair<int, int> >::iterator it;
bool g, f;
void calc(int xx, int yy) {
	if (vis[xx][yy])
		return;

	vis[xx][yy] = 1;
	for (int i = 0; i < d.size(); ++i) {
		int nx = xx + d[i].first;
		int ny = yy + d[i].second;
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] != -1) {
			calc(nx, ny);
			vis[nx][ny]++;
		}
	}

	return;
}
int main() {
	//freopen("A.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int t, tt = 1;
	scanf("%d", &t);
	while (t--) {
		st.clear();
		d.clear();
		memset(vis, 0, sizeof(vis));

		memset(vis2, 0, sizeof(vis2));
		scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &x, &y);
			vis[x][y] = -1;
		}
		odd = 0, even = 0;
		st.insert(mp(+a, +b));
		st.insert(mp(+a, -b));
		st.insert(mp(-a, -b));
		st.insert(mp(-a, +b));

		st.insert(mp(+b, +a));
		st.insert(mp(+b, -a));
		st.insert(mp(-b, -a));
		st.insert(mp(-b, +a));
		for (it = st.begin(); it != st.end(); it++) {
			x = (*it).first;
			y = (*it).second;
			d.push_back(mp(x, y));
		}

		calc(0, 0);
	//	printf("Case %d: %d %d\n", tt++, even, odd);
		odd = 0, even = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((i == j && i == 0) || vis[i][j] >= 1)
					if (vis[i][j] % 2 == 1) {
						odd++;
					} else
						even++;
		printf("Case %d: %d %d\n", tt++, odd, even);

	}
	return 0;
}


