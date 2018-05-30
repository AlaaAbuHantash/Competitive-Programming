#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int a[200005];
int f[1000005];
long long ans[200005];
pair<pair<int, int>, int> v[200005];
int blk;
inline bool comp(const pair<pair<int, int>, int> &a,
		const pair<pair<int, int>, int> &b) {
	int la = a.first.first / blk;
	int lb = b.first.first / blk;
	if (la != lb)
		return la < lb;
	int ra = a.first.second / blk;
	int rb = b.first.second / blk;
	return ra < rb;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	blk = ceil(sqrt(n));
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	int x, y;
	for (int k = 0; k < m; k++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		v[k].first.first = x;
		v[k].first.second = y;
		v[k].second = k;
	}
	sort(v, v + m, comp);
	int st = 0, ed = -1;
	long long sum = 0;

	for (int k = 0; k < m; k++) {
		x = v[k].first.first;
		y = v[k].first.second;
		int ind = v[k].second;
		if (x > st) {
			for (int i = st; i < x; i++) {
				sum -= (long long) f[a[i]] * f[a[i]] * a[i];
				f[a[i]]--;
				sum += (long long) f[a[i]] * f[a[i]] * a[i];
			}

		} else if (x < st) {
			for (int i = st - 1; i >= x; i--) {
				sum -= (long long) f[a[i]] * f[a[i]] * a[i];
				f[a[i]]++;
				sum += (long long) f[a[i]] * f[a[i]] * a[i];
			}
		}

		if (y > ed) {
			for (int i = ed + 1; i <= y; i++) {
				sum -= (long long) f[a[i]] * f[a[i]] * a[i];
				f[a[i]]++;
				sum += (long long) f[a[i]] * f[a[i]] * a[i];
			}

		} else if (y < ed) {
			for (int i = ed; i > y; i--) {
				sum -= (long long) f[a[i]] * f[a[i]] * a[i];
				f[a[i]]--;
				sum += (long long) f[a[i]] * f[a[i]] * a[i];
			}

		}
		st = x, ed = y;
		ans[ind] = sum;
	}

	for (int i = 0; i < m; i++) {
		printf("%lld\n", ans[i]);
	}

	return 0;
}
