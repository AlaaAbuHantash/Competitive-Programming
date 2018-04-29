#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input", "rt", stdin);
	int n, x;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	int a = 0, b = 0, aa = 0, bb = 0;

	for (int i = 0, j = n - 1; i < n && j >= 0;) {

		if (i > j) {
			break;
		} else if (n % 2 && i == j) {
			if (a <= b)
				aa++;
			break;
		}
		if (a == b) {
			a += v[i];
			b += v[j];
			aa++;
			j--;
			i++;
		} else if (b > a) {
			a += v[i];
			i++;
			aa++;
		} else {
			b += v[j];
			j--;

		}

	}

	cout << aa << " " << n-aa << endl;
	return 0;
}

