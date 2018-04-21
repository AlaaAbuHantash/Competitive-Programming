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
int a[30005];
int r[1000004];
int qq[200002];
 
struct st {
	int x, y, ind;
};
int sq;
st v[200002];
bool cmp(st tmp1, st tmp2) {
	if (tmp1.x / sq < tmp2.x / sq)
		return true;
	if (tmp1.x / sq > tmp2.x / sq)
		return false;
	if (tmp1.y < tmp2.y)
		return true;
	return false;
}
int main() {
	//freopen("b.txt", "rt", stdin);
	int n, x, y, q, res = 0;
	scanf("%d", &n);
 
	sq = sqrt(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i + 1]);
 
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &v[i].x, &v[i].y);
		v[i].ind = i;
	}
 
	res = 0;
	sort(v, v + q, cmp);
	int xx = 0, yy = 0;
	for (int i = 0; i < q; i++) {
		x = v[i].x, y = v[i].y;
		while (xx < x) {
			r[a[xx]]--;
			if (r[a[xx]] == 0)
				res--;
			xx++;
		}
		while (xx > x) {
			xx--;
			r[a[xx]]++;
			if (r[a[xx]] == 1)
				res++;
		}
 
		while (yy < y) {
			yy++;
			r[a[yy]]++;
			if (r[a[yy]] == 1)
				res++;
 
		}
		while (yy > y) {
			r[a[yy]]--;
			if (r[a[yy]] == 0)
				res--;
			yy--;
		}
 
		qq[v[i].ind] = res;
		//cout << r[1] << " " << r[2] << " " << r[3] << endl;
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", qq[i]);
	return 0;
}
