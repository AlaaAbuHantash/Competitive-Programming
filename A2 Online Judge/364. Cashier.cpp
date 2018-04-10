#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
int a[101];
int main() {
	int n;
	while (cin >> n) {
		if (!n)
			break;
		a[n]++;
	}
	for (int i = 1; i <= 100; i++)
		if (a[i])
			printf("%d %d\n", i, a[i]);

	return 0;
}

