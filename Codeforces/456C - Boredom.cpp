#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
long long v[100005];
long long  dp[100005][2];
int n, a, mx = 0;
long long calc(int ind, int st) {
//	cout << ind  << " " << st << endl;
	if (ind > mx)
		return 0;
	long long r = 0;
	if(dp[ind][st]!= -1 )
		return dp[ind][st];
	if (!st) {
		r = max(r, calc(ind + 1, 0));
		r = max(r, calc(ind + 1, 1) + (v[ind] * ind));
	} else
		r = max(r, calc(ind + 1, 0));

	return dp[ind][st]=r;
}
int main() {
	//freopen("input", "rt", stdin);
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[a]++;
		mx = max(mx, a);
	}
	cout << calc(0, 0) << "\n";
	return 0;
}

