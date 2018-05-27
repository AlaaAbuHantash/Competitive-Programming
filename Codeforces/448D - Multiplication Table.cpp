#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {

	//freopen("a.txt", "r", stdin);
	long long n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);

	long long l = 1;
	long long r = n * m;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long res = 0;
		int c = 0;
		for (int i = 1; i <= n; i++) {
			long long x = mid / i;
			res += min(x, m);
			if (mid % i == 0 && mid / i <= m) {
				c++;
			}
		}

		if (res >= k && res - c < k) {
			printf("%lld\n", mid);
			return 0;
		}

		if (res < k) {
			l = mid + 1;
		} else
			r = mid - 1;
	}
	return 0;
}
