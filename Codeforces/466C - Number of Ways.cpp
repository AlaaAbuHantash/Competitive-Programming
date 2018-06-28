#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
long long arr[555555], aa[555555], bb[555555];
int main() {
	//freopen("input", "rt", stdin);
	long long n, x, sum = 0, s = 0;
	cin >> n;
	arr[0] = 0;
	vector<int> a, b;
	vector<long long> v;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum += x;
		arr[i] += arr[i - 1] + x;
		v.push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		s += v[i - 1];
		if (s == sum / 3) {
			aa[i] = 1;
		}
		aa[i] += aa[i - 1];
		if (s == sum * 2 / 3)
			bb[i] = 1;
	}
	
	if (sum % 3)
		puts("0");
	else {
		long long res = 0;

		for (int i = 2; i < n; i++) {
			if (bb[i] == 1 && arr[n] - arr[i] == sum / 3)
				res += aa[i - 1];

		}
		cout << res << "\n";

	}
	return 0;
}

