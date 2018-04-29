#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<set>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
long long n, nub;
long long res = 4444477777;
bool f = 0;
void calc(int ind, int a, int b, long long int s) {
	if (ind == n) {
		if (a == b && s >= nub) {
			f = 1;
			res = min(res, s);
			return;
		}
		return;
	}
	calc(ind + 1, a + 1, b, s + pow(10.0, ind) * 4);
	calc(ind + 1, a, b + 1, s + pow(10.0, ind) * 7);

	return;
}
int main() {
	string s;
	cin >> s;
	n = s.length();
	nub = atoi(s.c_str());
	while (!f) {
		calc(0, 0, 0, 0);
		n++;
	}

	cout << res << endl;
	return 0;
}

