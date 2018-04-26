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
int n, m;
const int M = 1000000007;
string s;
long long r[111];
int vis[111][33];
int main() {
	//freopen("b.txt", "rt", stdin);
	scanf("%d%d", &n, &m);
	long long res = 1;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			if (!vis[j][s[j] - 'A'])
				r[j]++, vis[j][s[j] - 'A'] = 1;

	}
	for (int i = 0; i < m; i++)
		res = ((long long) (r[i] % M) * (long long) (res % M)) % M;

	printf("%I64d\n", res % M);
	return 0;
}

