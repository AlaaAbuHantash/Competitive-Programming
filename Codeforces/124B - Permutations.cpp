#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
#define mp make_pair
int n, k;
vector<string> v;
int main() {
	//freopen("input", "rt", stdin);
	cin >> n >> k;
	string s = "", x;
	for (int i = 0; i < k; i++)
		s += char(i + '0');
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int res = atoi(v[n - 1].c_str()) - atoi(v[0].c_str());
	while (next_permutation(s.begin(), s.end())) {
		int a = 2e9;
		int b = 0;
		for (int i = 0; i < n; i++) {
			int nub = 0;
			for (int j = 0, c = k - 1; j < k; j++ , c--)
				nub += pow(10.0, c) * (v[i][s[j]-'0']-'0');

			a = min(nub, a);
			b = max(nub, b);
		}
		res = min(res, b - a);
	}
	cout << res << "\n";
	return 0;
}

