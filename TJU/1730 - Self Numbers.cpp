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
int vis[1000005];
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i <= 10000; i++) {
		int x = i, sum = i;
		while (x != 0) {
			sum += x % 10;
			x = x / 10;
		}
		vis[sum] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!vis[i])
			printf("%d\n", i);
	}
	return 0;
}
