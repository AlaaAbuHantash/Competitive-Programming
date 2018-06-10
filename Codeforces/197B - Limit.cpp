#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}
int main() {
	//freopen("input", "rt", stdin);
	int n, m, x;
	scanf("%d%d", &n, &m);
	vector<int> a, b;
	for (int i = 0; i <= n; i++) {
		scanf("%d", &x);
		a.push_back(x);
	}

	for (int i = 0; i <= m; i++) {
		scanf("%d", &x);
		b.push_back(x);
	}
	if (n == m) {
		int z = gcd(a[0], b[0]);
		int g = 1;
		if ((a[0] < 0 || b[0] < 0) && !(b[0] < 0 && a[0] < 0))
			g = -1;
		if (z < 0) {
			z *= -1;
		}
		if (a[0] < 0)
			a[0] *= -1;

		if (b[0] < 0)
			b[0] *= -1;

		printf("%d/%d\n", a[0] / z * g, b[0] / z);
	} else if (n > m) {
		if ((a[0] < 0 || b[0] < 0) && !(b[0] < 0 && a[0] < 0))
			printf("-");
		puts("Infinity");
	} else
		puts("0/1");

	return 0;
}

