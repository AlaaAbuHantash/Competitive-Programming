#include <iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int t, s, n, a, b, z;
long long dp[5055][55];
int vis[5055][55];
vector<pair<int, int> > p;
#define mp make_pair
int id;
long long calc(int sum, int ind) {
	if (sum == s && ind == n)
		return 1;
	if (sum > s || ind == n)
		return 0;
	if (vis[sum][ind] == id)
		return dp[sum][ind];

	long long r = 0;
	r += calc(sum, ind + 1);
	if (p[ind].second >= z) {
		r += calc(sum + (p[ind].first * z), ind + 1);
	}
	vis[sum][ind] = id;
	return dp[sum][ind] = r;
}
int main() {
	id = 0;
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int tt = 1;
	cin >> t;
	while (t--) {

		cin >> s >> n;
		p.clear();
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			p.push_back(mp(a, b));
			mx = max(mx, b);
		}
		long long res = 0;
		for (int i = 0; i <= mx; i++) {
			z = i;
			id++;
			res += calc(0, 0);
		}
		printf("Case %d: ", tt++);
		cout << res << endl;

	}
	return 0;
}

