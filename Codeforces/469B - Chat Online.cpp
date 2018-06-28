#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<set>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int v[2000];
int vis[2000];
int main() {
	//freopen("input", "rt", stdin);
	int n, m, a, b, x, y;
	cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = x; j <= y; j++)
			v[j] = 1;
	}
	int c = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		for (int j = a; j <= b; j++) {
			int r = 0;
			int nx = x + j;
			int ny = y + j;
			for (int k = nx; k <= ny && !r; k++) {
				if (v[k])
					r = 1;
			}
			if (r && !vis[j]) {
				c++;
				vis[j] = 1;
			}

		}

	}
	cout << c << "\n";
	return 0;
}

