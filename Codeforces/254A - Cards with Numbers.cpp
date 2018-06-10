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
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
int v[5004];
//vector<pair<int, int> > p;
int m[5004];
int a[3 * 100000 + 2];
int b[3 * 100000 + 2];
int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, k = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> x;
		if (m[x] >= 1) {
			m[x]--;

			a[k] = v[x];
			b[k] = i;
			k++;
		} else {
			v[x] = i;
			m[x]++;
		}

	}

	if (k == n)
		for (int i = 0; i < n; i++)
			printf("%d %d\n", a[i]+1, b[i]+1);
	else
		puts("-1");
	return 0;
}

