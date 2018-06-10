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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a, b, c;
int main() {
	//freopen("input", "rt", stdin);
	int n, a, b;
	cin >> n >> a;
	long long int res = a + 1;
	for (int i = 1; i < n; i++) {
		cin >> b;
		res += abs(b - a) + 2;
		a = b;
	}
	cout << res << "\n";
	return 0;
}

