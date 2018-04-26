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
int a[5][5];
int main() {
	//freopen("b.txt", "rt", stdin);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &a[i][j]);

	int res = 0;
	string s = "01234";
	do {
		int x = a[s[0] - '0'][s[1] - '0'] + 2 * a[s[2] - '0'][s[3] - '0']
				+ a[s[1] - '0'][s[2] - '0'] + 2 * a[s[3] - '0'][s[4] - '0'];
		x+= a[s[1] - '0'][s[0] - '0'] + 2 * a[s[3] - '0'][s[2] - '0']
				+ a[s[2] - '0'][s[1] - '0'] + 2 * a[s[4] - '0'][s[3] - '0'];
		res = max(x, res);
	} while (next_permutation(s.begin(), s.end()));
	printf("%d\n", res);
	return 0;
}

