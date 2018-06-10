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
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input", "rt", stdin);
	int n, x, s = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s += x;
	}
	n++;
	x = (s % n);
	int r = 0;
	for (int i = 1; i <= 5; i++) {
		if ((x + i) % n != 1)
			r++;
	}
	printf("%d\n", r);
	return 0;
}

