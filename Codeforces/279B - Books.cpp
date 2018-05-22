#include <bits/stdc++.h>
using namespace std;
int x[100005];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);

	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	int st = 0, res = 0;
	int tmpsum = 0;
	for (int i = 0; i < n; i++) {
		tmpsum += x[i];

		if (tmpsum > s) {
			while (tmpsum > s && st <= i) {
				tmpsum -= x[st];
				st++;
			}
		}

		if (tmpsum <= s) {
			res = max(res, i - st + 1);
		}
	}
	printf("%d\n", res);
	return 0;
}

