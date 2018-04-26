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
int vis[50005];
int v[50005];
int c[50005];
int r;
void calc(int node) {
	//cout << node << " " << r << endl;
	if (vis[node])
		return;
	vis[node] = 1;
	calc(v[node]);

	c[node] += r;
	r++;
	vis[node] = 0;
}

int main() {
//freopen("A.txt" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);

	int t, n, x, y, tt = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			v[x - 1] = y - 1;
			vis[i] = 0;
			c[i] = 1;

		}
		int res = 0;

		for (int i = 0; i < n; i++) {
			if (c[i] == 1) {
				//cout << " i << " << i << endl;
				r = 0;
				calc(i);
				if (r > res) {
					res = r;
					x = i;
				} else if (r == res) {
					x = min(i, x);
				}
			}

		}

		printf("Case %d: %d\n", tt++, x + 1);
	}
	return 0;
}


