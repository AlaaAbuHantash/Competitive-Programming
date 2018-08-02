#include <bits/stdc++.h>
using namespace std;
int vis[105][105];
string s = "ALLIZZWELL";
vector<string> v;
int n, m;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
bool calc(int x, int y, int ind) {
	if (ind == s.size())
		return true;
	bool ans = false;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && v[nx][ny] == s[ind]
				&& !ans && !vis[nx][ny]) {
			vis[nx][ny] = 1;
			ans |= calc(nx, ny, ind + 1);
			vis[nx][ny] = 0;
		}
	}
	return ans;
}
int main() {
	//freopen("a.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		string str;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> str;
			v.push_back(str);
		}
		bool f = 0;
		for (int i = 0; i < n && !f; i++)
			for (int j = 0; j < m && !f; j++) {
				if (v[i][j] == s[0]) {
					vis[i][j] = 1;
					f = calc(i, j, 1);
					vis[i][j] = 0;
				}
			}

		if (f)
			puts("YES");
		else
			puts("NO");

	}
	return 0;
}

