#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m, a, b;
vector<pair<int, int> > p;
int v[11111];
int vis[1111][1111];
int main() {
	//freopen("input", "rt", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v[b]++;
		vis[a][b]++;

	}
	int c = 0, cc = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (v[b]) {
			v[b]--;
			c++;
		}
		if (vis[a][b]) {
			vis[a][b]--;
			cc++;
		}
	}
	printf("%d %d\n", c, cc);
	return 0;
}

