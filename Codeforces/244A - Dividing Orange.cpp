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
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, x, k;
vector<int> v;
int vis[30 * 30 + 2];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		cin >> x;
		vis[x] = 1;
		v.push_back(x);
	}
	for (int i = 0; i < k; i++) {
		cout << v[i] << " ";
		int nn = n - 1;
		for (int j = 1; j <= n * k && nn; j++)
			if (!vis[j]) {
				cout << j << " ";
				vis[j] = 1;
				nn--;
			}
		puts("");
	}

	return 0;
}


