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
using namespace std;
int dx[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int dy[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
#define mp make_pair
int a[100005];
int main() {
	//freopen("test.txt", "rt", stdin);
	string s;
	cin >> s;

	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] == s[i])
			a[i]++;
		a[i] += a[i - 1];
	}
	int n, x, y;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", a[y - 1] - a[x - 1]);
	}

	return 0;
}


