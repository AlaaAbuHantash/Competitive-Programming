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
char p[33];

int main() {

	//freopen("a.txt", "rt", stdin);
	int n, m;
	string s;
	char a, b;
	cin >> n >> m >> s;
	for (int i = 0; i < s.length(); i++) {
		p[s[i] - 'a'] = s[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (char j = 'a'; j <= 'z'; j++) {
			if (p[j - 'a'] == a) {
				p[j - 'a'] = b;
			} else if (p[j - 'a'] == b) {
				p[j - 'a'] = a;
			}
		}

	}

	for (int i = 0; i < s.length(); i++)
		s[i] = p[s[i] - 'a'];
	cout << s << endl;
	return 0;
}

