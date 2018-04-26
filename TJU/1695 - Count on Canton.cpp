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
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int const M = 1e7;
int cnt[5000];
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < 4475; i++)
		cnt[i] = cnt[i - 1] + i;

	int n;
	while (cin >> n) {
		int ind = 0;
		for (int i = 1; i < 4475; i++)
			if (cnt[i - 1] <= n && cnt[i] >= n) {
				ind = i;
				break;
			}
		int aa = 1, bb = ind , x = cnt[ind-1]+1;
		while (x != n)
			aa++, bb--,x++;
		if (ind%2)
			printf("TERM %d IS %d/%d\n", n, bb, aa);
		else
			printf("TERM %d IS %d/%d\n", n, aa, bb);

	}
	return 0;
}

