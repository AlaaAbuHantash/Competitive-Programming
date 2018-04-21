#define _CRT_SECURE_NO_WARNINGS
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
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a[200004];
int cnt[1000002];
long long qq[200001];
int n, m, x, y, sq;
struct st {
	int x, y, ind;
} v[200001];
bool cmp(st a, st b) {
	if (a.x / sq < b.x / sq)
		return 1;
	if (b.x / sq < a.x / sq)
		return 0;
	return a.y < b.y;
}
int main() {
	//freopen("b.txt", "rt", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sq = sqrt(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &v[i].x, &v[i].y);
		v[i].ind = i;
	}
	sort(v, v + m, cmp);
	int xx = 0, yy = 0;
	long long res = 0;
	for (int i = 0; i < m; i++) {
		x = v[i].x, y = v[i].y;
		while (xx < x) {
			res -= (long long) cnt[a[xx]] * (long long) cnt[a[xx]]
					* (long long) a[xx];
			cnt[a[xx]]--;
			res += (long long) (cnt[a[xx]] * (long long) cnt[a[xx]]
					* (long long) a[xx]);
			xx++;
		}
		while (xx > x) {
			xx--;
			res -= (long long) cnt[a[xx]] * (long long) cnt[a[xx]]
					* (long long) a[xx];
			cnt[a[xx]]++;
			res += (long long) (cnt[a[xx]] * (long long) cnt[a[xx]]
					* (long long) a[xx]);
		}
		while (yy < y) {
			yy++;
			res -= (long long) cnt[a[yy]] * (long long) cnt[a[yy]]
					* (long long) a[yy];
			cnt[a[yy]]++;
			res += (long long) cnt[a[yy]] * (long long) cnt[a[yy]]
					* (long long) a[yy];
		}
		while (yy > y) {
			res -= (long long) cnt[a[yy]] * (long long) cnt[a[yy]]
					* (long long) a[yy];
			cnt[a[yy]]--;
			res += (long long) cnt[a[yy]] * (long long) cnt[a[yy]]
					* (long long) a[yy];
			yy--;
		}
		qq[v[i].ind] = res;
		//cout << res << endl;
	}
	for (int i = 0; i < m; i++)
		printf("%I64d\n", qq[i]);

	return 0;
}
