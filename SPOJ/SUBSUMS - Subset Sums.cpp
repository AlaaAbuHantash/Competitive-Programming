#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n;
long long a, b;
vector<long long> v;
vector<long long> sum1, sum2;
int offset, sz;
void calc(int ind, long long sum, int f) {
	if (ind == sz) {
		if (f && !offset)
			sum1.push_back(sum);
		else if (f)
			sum2.push_back(sum);
		return;
	}

	calc(ind + 1, sum, f);
	calc(ind + 1, sum + v[ind + offset], 1);
}
int main() {
	//freopen("a.txt", "r", stdin);

	cin >> n >> a >> b;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	sz = n / 2;
	offset = 0;
	calc(0, 0, 0);

	sz = n / 2 + n % 2;
	offset = n / 2;
	calc(0, 0, 0);
	sum2.push_back(0);
	sum1.push_back(0);
	sort(sum2.begin(), sum2.end());

	long long res = 0;

	for (int i = 0; i < sum1.size(); i++) {
		long long val = sum1[i];
		int aa = lower_bound(sum2.begin(), sum2.end(), a - val) - sum2.begin();
		int bb = upper_bound(sum2.begin(), sum2.end(), b - val) - sum2.begin();
		res += bb - aa;
	}
	printf("%lld\n", res);

}

