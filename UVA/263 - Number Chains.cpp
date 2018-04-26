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
int main() {
	//freopen("A.txt", "rt", stdin);
	string s;
	bool f = 0;
	map<int, int> m;
	while (cin >> s && s != "0") {

		m.clear();
		printf("Original number was ");
		cout << s << "\n";
		int res = 0;
		while (1) {
			sort(s.rbegin(), s.rend());
			cout << s << " - ";
			int a = atoi(s.c_str());

			reverse(s.begin(), s.end());
			a -= atoi(s.c_str());

			int len = s.length();
			for (int i = 0, r = 0; i < len; i++)
				if (s[i] != '0') {
					if (r)
						s = s.erase(0, r);
					break;
				} else
					r++;
			if (s.empty())
				s = "0";
			cout << s << " = " << a << endl;
			res++;
			if (m[a])
				break;
			m[a] = 1;
			string g = "";
			if (a == 0)
				g = "0";
			else
				while (a) {
					g += char(a % 10 + '0');
					a = a / 10;
				}

//			cout <<g <<endl;
			s = g;
		}
		printf("Chain length %d\n", res);
		puts("");

	}
	return 0;
}

