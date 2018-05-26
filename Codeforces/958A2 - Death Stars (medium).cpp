#include <bits/stdc++.h>

using namespace std;
char a[2002][202];
char b[202][2002];
int hs2[202][2002];
int _hs2[202][2002];
int M1 = 1e9 + 7;
int M2 = 1e9 + 9;
int n, m;

unordered_map<int, vector<int> > rep;
vector<int> v;
vector<int> v2;
void hash1(int ind) {

	int h = 1, h2 = 1;
	for (int i = 0; i < m; i++) {
		h = ((h * 26) + (a[ind][i] - 'a' + 1)) % M1;
		h2 = ((h2 * 26) + (a[ind][i] - 'a' + 1)) % M2;
	}
	rep[h].push_back(ind + 1);
	v.push_back(h);
	v2.push_back(h2);

}
void hash2(int ind) {

	for (int i = 0; i <= n - m; i++) {
		int h = 1, h2 = 1;
		for (int j = 0; j < m; j++) {
			h = ((h * 26) + (b[ind][i + j] - 'a' + 1)) % M1;
			h2 = ((h2 * 26) + (b[ind][i + j] - 'a' + 1)) % M2;

		}
		hs2[ind][i] = h;
		_hs2[ind][i] = h2;

	}
}
int main(int argc, char **argv) {

//	freopen("a.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
		hash1(i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", b[i]);
		hash2(i);
	}

	for (int j = 0; j <= n - m; j++) {
		if (!rep[hs2[0][j]].empty()) {
			int sz = rep[hs2[0][j]].size();
			for (int g = 0; g < sz; g++) {
				int ind = rep[hs2[0][j]][g] - 1;
				int tmp = ind + 1;
				bool f = 1;
				if (n - ind < m)
					f = 0;
				for (int k = 0; k < m && f; k++, ind++) {
					if (v[ind] != hs2[k][j] || v2[ind] != _hs2[k][j])
						f = 0;
				}
				if (f) {
					printf("%d %d\n", tmp, j + 1);
					return 0;
				}
			}

		}

	}

	return 0;
}
