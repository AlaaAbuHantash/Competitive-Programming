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
int n, s;
bool f;
void calc(int sum, int ind) {
	if (f)
		return;
	if (s == sum && ind == n) {
		f = 1;
		return;
	}
	if (ind == n)
		return;
	calc(sum - (ind + 1), ind + 1);
	calc(sum + (ind + 1), ind + 1);

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		f = 0;
		cin >> n >> s;
		calc(0, 0);
		if (f)
			puts("Possible");
		else
			puts("Impossible");
	}
	return 0;
}

