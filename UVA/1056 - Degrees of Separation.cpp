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
string a, b;
int main() {
	//freopen("A.txt", "rt", stdin);

	int n, m, tt = 1;
	map<string, int> ma;
	while (scanf("%d%d", &n, &m) > 0) {
		if (n + m == 0)
			return 0;
		int c = 1;
		ma.clear();
		vector<vector<int> > v(n + 1, vector<int>(n + 1, -1));
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (ma[a] == 0)
				ma[a] = c++;
			if (ma[b] == 0)
				ma[b] = c++;
			v[ma[a]][ma[b]] = 1;
			v[ma[b]][ma[a]] = 1;
		//	cout << a << " " << b << " " << ma[a] << " " << ma[b] << endl;
		}

		printf("Network %d: ", tt++);

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (v[i][k] != -1 && v[k][j] != -1) {
						if (v[i][j] == -1)
							v[i][j] = v[i][k] + v[k][j];
						else
							v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

					}

		bool f = 1;
		int res = 0;
		for (int i = 1; i <= n && f; i++)
			for (int j = 1; j <= n && f; j++) {

				if (i == j)
					continue;
				//cout << v[i][j] << " " << i << " " << j << endl;
				if (v[i][j] == -1)
					f = 0;
				else
					res = max(res, v[i][j]);
			}

		if (f)
			printf("%d\n", res);
		else
			puts("DISCONNECTED");
		puts("");

	}
	return 0;
}

