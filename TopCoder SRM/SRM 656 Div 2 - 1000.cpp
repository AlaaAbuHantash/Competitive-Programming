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
#define mp make_pair
int a[222], n;
int vis[222];
long long dp[222][222][3];
class PermutationCountsDiv2 {
public:
	int countPermutations(int N, vector<int> pos) {
		n = N;
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < pos.size(); i++) {
			a[pos[i] - 1] = 1;
		}

		long long res = 0;
		for (int i = 1; i <= n; i++) {
			vis[i] = 1;
			if (a[0] == 1) {
				res = (res + calc(1, i, 1)) % 1000000007;
			} else
				res = (res + calc(1, i, 0)) % 1000000007;
			vis[i] = 0;
		}
		cout << res << endl;
		return res % 1000000007;
	}
	long long calc(int nub, int pre, int op) {
		if (nub == n)
			return 1;
		long long r = 0;
		if (dp[nub][pre][op] != -1)
			return dp[nub][pre][op];
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				vis[i] = 1;
				if (op == 1 && pre < i) {
					if (a[nub])
						r = (r + calc(nub + 1, i, 1) % 1000000007);
					else
						r = (r + calc(nub + 1, i, 0) % 1000000007);
				} else if (op == 0 && pre > i) {
					if (a[nub])
						r = (r + calc(nub + 1, i, 1) % 1000000007);
					else {
						r = (r + calc(nub + 1, i, 0) % 1000000007);
					}
				}

				vis[i] = 0;
			}
		}
		return dp[nub][pre][op] = r;
	}

};

int main() {

	//freopen("input", "rt", stdin);
	PermutationCountsDiv2 p;
	vector<int> v;
	p.countPermutations(200, v);
	return 0;
}
