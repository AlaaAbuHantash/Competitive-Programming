#include <bits/stdc++.h>
using namespace std;
long long cum[100005];
long long ans[100005];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);

	int n, q, k;
	scanf("%d", &n);
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	sort(v.rbegin(), v.rend());

	for (int i = 1; i <= n; i++) {
		cum[i] = cum[i - 1] + v[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		long long st = 1;
		long long lev = 1;
		long long add = i;
		long long res = 0;
		while (st < n) {
			long long mn = min((long long) n, st + add);
			long long s = cum[int(mn)] - cum[min(n, (int) st)];
			res += s * lev;
			lev++;
			st = st + add;
			add = add * i;
		}
		ans[i] = res;

	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &k);
		printf("%lld ", ans[min(n, k)]);
	}
	return 0;
}

