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
int a[55][55], aa, bb;
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, m, x;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++) {
			scanf("%d", &x);
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
		}
	scanf("%d%d", &aa, &bb);
	int res = n * m;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				if (aa + j <= n && bb + k <= m) {
					int rr = a[aa + j][bb + k] - a[aa + j][k] - a[j][bb + k]
							+ a[j][k];
					res = min(res, rr);
				}
			}
		swap(aa, bb);
	}
	printf("%d\n", res);
	return 0;
}

