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
	puts("         NAME                     SOUNDEX CODE");
	while (cin >> s) {
		string tmp = "";
		bool f = 0;
		tmp = char(s[0]) + tmp;
		string z = "";
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O'
					|| s[i] == 'U' || s[i] == 'Y' || s[i] == 'W' || s[i] == 'H' ) {
				z += "#";
			} else {
				if ((s[i] == 'B' || s[i] == 'P' || s[i] == 'F' || s[i] == 'V'))
					z += "1";
				else if ((s[i] == 'C' || s[i] == 'S' || s[i] == 'K'
						|| s[i] == 'G' || s[i] == 'J' || s[i] == 'Q'
						|| s[i] == 'X' || s[i] == 'Z'))
					z += "2";
				else if ((s[i] == 'D' || s[i] == 'T'))
					z += "3";
				else if (s[i] == 'L')
					z += "4";
				else if (s[i] == 'M' || s[i] == 'N')
					z += "5";
				else if ((s[i] == 'R'))
					z += "6";

				int len = z.length();
				if (len >= 2) {
					if (z[len - 1] != z[len - 2] && z[len - 1] != '#')
						tmp += char(z[len - 1]);
				}
				f = 0;
			}
		}

		if (tmp.size() > 4)
			tmp = tmp.substr(0, 4);
		else if (tmp.size() < 4) {
			for (int i = tmp.size(); i < 4; i++)
				tmp += "0";
		}
		printf("         ");
		cout << s;
		for (int i = 0; i < 25 - s.length(); i++)
			printf(" ");
		cout << tmp << endl;

	}
	puts("                   END OF OUTPUT");

	return 0;
}

