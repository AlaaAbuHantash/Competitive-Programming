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
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int a[1000][1000];
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int pre = 0, g;
	for (int i = 2;; i++) {
		int x = i + ((i - 1) * i / 2);
		if (x > n)
			break;
		pre = i + 1;
		g = x;

	}
	cout << pre << endl;
	int lst = 1;
	for (int i = 0; i < pre; i++) {

		if (i == 0) {
			for (int j = 0; j < pre - 1; j++) {
				printf("%d ", j + 1);
				a[0][j] = j + 1;
			}
			lst = pre;
		} else {
			for (int j = 0; j < i; j++)
				printf("%d ", a[j][i - 1]);
			for (int j = 0; j < pre - 1 - i; j++) {
				printf("%d ", lst);
				a[i][i + j] = lst;
				lst++;
			}

		}
		puts("");
	}
	return 0;
}

