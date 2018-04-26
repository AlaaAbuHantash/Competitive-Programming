#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
using namespace std;
#define mp make_pair
int a[401][401];
int main() {

	//freopen("test.txt", "rt", stdin);
	int n;
	string s;
	while (cin >> n && n) {
		cin >> s;
		memset(a, 0, sizeof(a));
		int m = (s.length()) / n, k = 0;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++, k++)
				a[i][j] = s[k] - '0';

		int c = 6;
		int nub = 0;
		string tmp = "";
		bool f = 0;
		for (int i = 0; i < n && !f; i++)
			for (int j = i, k = 0; j >= 0 && !f; j--, k++) {

				nub += pow(2.0, c) * a[k][j];
				c--;

				if (c == -1) {
					c = 6;
					if (nub == 0) {
						f = 1;
						break;
					}
					tmp += char(nub);
					nub = 0;
				}
			}


		for (int i = 1; i < m && !f; i++)
			for (int k = i, j = n - 1; j >= 0 && !f; k++, j--) {
				if (k == m)
					break;
				nub += pow(2.0, c) * a[k][j];
				c--;
				if (c == -1) {
					c = 6;
					if (nub == 0) {
						f = 1;
						break;
					}
					tmp += char(nub);
					nub = 0;
				}
			}
		cout << tmp << endl;
	}
	return 0;
}