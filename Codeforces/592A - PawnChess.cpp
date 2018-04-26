#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s[9];
int main() {

	//freopen("a.txt", "rt", stdin);
	for (int i = 0; i < 8; i++)
		cin >> s[i];
	int a = -1, b = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s[j][i] == 'B')
				break;
			if (s[j][i] == 'W') {
				if (a == -1)
					a = j;
				a = min(a, j);
				break;
			}
		}
		for (int j = 7; j >= 0; j--) {
			if (s[j][i] == 'W')
				break;
			if (s[j][i] == 'B') {
				if (b == -1)
					b = j;
				b = max(b, j);
			}
		}
	}
	if (a == -1 || 7 - b < a)
		puts("B");
	else
		puts("A");

	return 0;
}

