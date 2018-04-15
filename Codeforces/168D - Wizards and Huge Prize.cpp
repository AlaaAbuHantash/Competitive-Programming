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
bool vis[205][205][205];
int id, n, k, l;
vector<pair<int, double> > p;
double dp[205][205][205];
double calc(int ind, int ll, int kk) {

	if (ind == n) {
		if (ll >= l)
			return 1.0;
		return 0;
	}
	if (vis[ind][ll][kk])
		return dp[ind][ll][kk];
	vis[ind][ll][kk] = 1;
	double res = 0.0;
	res += calc(ind + 1, ll, kk) * (1.0 - p[ind].second);
	if (p[ind].first == -1 && kk >= 1)
		res += calc(ind + 1, ll + 1, kk - 1) * p[ind].second;
	else if (p[ind].first != -1)
		res += calc(ind + 1, ll + 1, min(n, kk + p[ind].first)) * p[ind].second;

	return dp[ind][ll][kk] = res;
}
int main() {
	//freopen("b.txt", "rt", stdin);
	cin >> n >> l >> k;
	p.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i].second), p[i].second /= 100.0;

	for (int i = 0; i < n; i++)
		scanf("%d", &p[i].first);

	sort(p.rbegin(), p.rend());

	printf("%.6lf\n", calc(0, 0, k));

	return 0;
}
