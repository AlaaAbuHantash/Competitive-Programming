#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[100005][2][2][2];
int calc(int ind, int f, int a, int lst) {
	if (ind == n)
		return 1;
	int r = 0;
	if (dp[ind][f][a][lst] != -1)
		return dp[ind][f][a][lst];
	if (f) {
		if (s[ind] - '0' == lst) {
			r = max(r, calc(ind + 1, f, a, !lst) + 1);
			r = max(r, calc(ind + 1, 0, a, !lst) + 1);
		}

		r = max(r, calc(ind + 1, f, a, lst));
		r = max(r, calc(ind + 1, 0, a, lst));
	} else {
		if (s[ind] - '0' != lst) {
			r = max(r, calc(ind + 1, f, a, !lst) + 1);
			if (!a)
				r = max(r, calc(ind + 1, 1, 1, !lst) + 1);
		}
		r = max(r, calc(ind + 1, f, a, lst));
		if (!a)
			r = max(r, calc(ind + 1, 1, 1, lst));
	}
	return dp[ind][f][a][lst] = r;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	printf("%d\n",
			max(calc(0, 1, 1, (s[0] - '0' + 1) % 2),
					calc(0, 0, 0, s[0] - '0')));
	return 0;
}
