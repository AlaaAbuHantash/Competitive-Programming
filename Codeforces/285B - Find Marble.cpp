#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a, b, c;
int vis[111111];
int main() {
	//freopen("input", "rt", stdin);
	int n, a, b, x;
	cin >> n >> a >> b;
	if (a == b) {
		puts("0");
		return 0;
	}
	vector<int> v;
	a--;
	b--;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x - 1);
	}
	int res = 0;
	bool f = 0;
	while (1) {
		if (vis[a])
			break;
		x = v[a];
		res++;
		if (x == b) {
			f = 1;
			break;
		}
		vis[a] = 1;
		a = x;
	}
	if (f)
		cout << res << "\n";
	else
		puts("-1");

	return 0;
}

