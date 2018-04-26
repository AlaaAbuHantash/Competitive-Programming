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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s, tmp;
int k, len;
const int N = 500;
int dp[N + 1][N + 1], dpp[N + 1][N + 1];
int pal(int l, int r) {
	if (l >= r)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	int res = 2e9;
	if (s[l] == s[r])
		res = min(res, pal(l + 1, r - 1));
	return dp[l][r] = min(res, pal(l + 1, r - 1) + 1);
}
int calc(int l, int sp) {
	if (l >= len)
		return 0;
	if (sp >= k)
		return 1e9;
	if (dpp[l][sp] != -1)
		return dpp[l][sp];
	int res = 2e9;
	for (int i = l; i < len; i++)
		res = min(res, calc(i + 1, sp + 1) + pal(l, i));
	return dpp[l][sp] = res;
}

void path(int l, int r) {
	if (l >= r)
		return;
	int res = pal(l + 1, r - 1) + 1;
	int rr = 2e9;
	if (s[l] == s[r])
		rr = pal(l + 1, r - 1);
	if (rr > res)
		tmp[l] = s[r];
	path(l + 1, r - 1);
}
void pth(int l, int sp) {

	if (l >= len)
		return;

	if (l != 0)
		printf("+");

	int ind = -1;
	int res = 2e9, r = 2e9;
	for (int i = l; i < len; i++) {
		r = calc(i + 1, sp + 1) + pal(l, i);
		if (r < res)
			ind = i, res = r;
	}
	path(l, ind);
	for (int i = l; i <= ind; i++)
		printf("%c", tmp[i]);
	pth(ind + 1, sp + 1);
}
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, -1, sizeof(dp));
	memset(dpp, -1, sizeof(dpp));
	cin >> s >> k;
	tmp = s;
	len = s.length();

	cout << calc(0, 0) << endl;
	pth(0, 0);

	return 0;
}

