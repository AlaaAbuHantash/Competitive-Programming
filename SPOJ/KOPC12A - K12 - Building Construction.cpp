#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int a[10001], c[10001];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &c[i]);
		}

		int l = 0;
		int r = 10000*2;
		long long res = 1e16;
		while (l <= r) {
			int mid1 = l + (r - l) / 3;
			int mid2 = r - (r - l) / 3;
			long long r1 = 0;
			for (int i = 0; i < n; i++) {
				r1 += (long long ) abs(mid1 - a[i]) * (long long )c[i];
			}
			long long r2 = 0;
			for (int i = 0; i < n; i++) {
				r2 += (long long ) abs(mid2 - a[i]) * (long long )c[i];
			}
			res = min(res, min(r1, r2));
			if (r1 < r2) {
				r = mid2 - 1;

			} else {
				l = mid1 + 1;
			}
		}
		printf("%lld\n", res);

	}
	return 0;
}
