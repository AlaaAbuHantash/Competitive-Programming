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
	//freopen("input", "rt", stdin);
	int n, m, d, x;
	cin >> n >> m >> d;
	vector<int> v;
	for (int i = 0; i < n * m; i++) {
		cin >> x;
		v.push_back(x);
	}
	//sort(v.begin(), v.end());
	long long res = -1;

	for (int j = 1; j <= 1e4; j++) {
		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (abs(v[i] - j) % d == 0)
				sum += abs(v[i] - j) / d;
			else {
				sum = -1;
				break;
			}
		}
		if (res == -1)
			res = sum;
		if (sum >= 0)
			res = min(res, sum);
	}
	cout << res << endl;
	return 0;
}

