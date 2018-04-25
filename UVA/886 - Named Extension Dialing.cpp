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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s;
string fun() {
	string g = "";
	int len = s.length();
	for (int i = 0; i < len; i++)
		if (s[i] == 'A' || s[i] == 'a' || s[i] == 'B' || s[i] == 'b'
				|| s[i] == 'C' || s[i] == 'c')
			g += "2";
		else if (s[i] == 'D' || s[i] == 'd' || s[i] == 'E' || s[i] == 'e'
				|| s[i] == 'F' || s[i] == 'f')
			g += "3";
		else if (s[i] == 'G' || s[i] == 'g' || s[i] == 'H' || s[i] == 'h'
				|| s[i] == 'I' || s[i] == 'i')
			g += "4";
		else if (s[i] == 'J' || s[i] == 'j' || s[i] == 'K' || s[i] == 'k'
				|| s[i] == 'L' || s[i] == 'l')
			g += "5";
		else if (s[i] == 'M' || s[i] == 'm' || s[i] == 'N' || s[i] == 'n'
				|| s[i] == 'O' || s[i] == 'o')
			g += "6";
		else if (s[i] == 'P' || s[i] == 'p' || s[i] == 'Q' || s[i] == 'q'
				|| s[i] == 'R' || s[i] == 'r' || s[i] == 'S' || s[i] == 's')
			g += "7";
		else if (s[i] == 'T' || s[i] == 't' || s[i] == 'U' || s[i] == 'u'
				|| s[i] == 'V' || s[i] == 'v')
			g += "8";
		else if (s[i] == 'W' || s[i] == 'w' || s[i] == 'X' || s[i] == 'x'
				|| s[i] == 'Y' || s[i] == 'y' || s[i] == 'Z' || s[i] == 'z')
			g += "9";
	return g;

}
map<string, bool> m;
map<string, vector<string> > ma;
map<string, bool> m2;
int main() {
	vector<pair<string, string> > g;
	//freopen("A.txt", "rt", stdin);
	string a, b, c;
	while (cin >> a) {
		if (a[0] >= '0' && a[0] <= '9')
			break;
		cin >> b >> c;
		m[c] = 1;
		s = "";
		s += a[0];
		a = fun();
		s = b;
		a = a + fun();
		g.push_back(mp(a, c));

	}

	do {
		int res = 0;
		if (!m[a]) {
			m2.clear();
			int aa = a.length();
			for (int i = 0; i < g.size(); ++i) {
				int j = 0;
				if (aa > g[i].first.length())
					continue;
				while (a[j] == g[i].first[j] && j < aa
						&& j < g[i].first.length())
					j++;

				if (j && j == aa) {
					if (res)
						printf(" ");
					printf("%s", (g[i].second).c_str());
					res = 1;
				}
			}
			if (res == 0)
				puts("0");
			else
				puts("");

		} else
			printf("%s\n", a.c_str());

	} while (cin >> a);
	return 0;
}

