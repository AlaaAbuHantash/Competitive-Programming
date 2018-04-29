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
int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
		if (n % i == 0) {
			n = i;
			printf("%d ", i);
		}

	return 0;
}

