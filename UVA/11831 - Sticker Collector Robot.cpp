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
#include <stdio.h>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m, s, x, y, c;
string ss, ins;
vector<string> v;
//` D E F ', meaning, respectively,
// turn 90 degrees to the right", \turn 90 degrees to the left"
int res;
void calc(int ind, int cur) {
	//cout << x << " " << y << " " << ind << " " << cur << endl;
	if (ind == s)
		return;
	if (ins[ind] == 'F') {
		if (cur == 0) {
			if (x - 1 >= 0 && v[x-1][y] != '#')
				x--;
			if (v[x][y] == '*') {
				res++;
				v[x][y] = '.';
			}
		} else if (cur == 1) {
			if (y + 1 < m && v[x][y+1] != '#')
				y++;
			if (v[x][y] == '*') {
				res++;
				v[x][y] = '.';
			}
		} else if (cur == 2) {
			if (x + 1 < n && v[x+1][y] != '#')
				x++;
			//cout << cur << " -  " << x  << " " << n << " "<<v[x][y] << endl;
			if (v[x][y] == '*') {
				res++;
				v[x][y] = '.';
			}
		} else if (cur == 3) {
			if (y - 1 >= 0 && v[x][y-1] != '#')
				y--;
			if (v[x][y] == '*') {
				res++;
				v[x][y] = '.';
			}

		}
		calc(ind + 1, cur);
	} else if (ins[ind] == 'D') {
		calc(ind + 1, (cur + 1) % 4);
	} else if (ins[ind] == 'E') {
		//cout << cur << " " << (cur - 1 + 4) % 4 << endl;
		calc(ind + 1, (cur - 1 + 4) % 4);
	}
}
int main() {
//freopen("A.txt" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);
	map<char, int> mm;
	mm['N'] = 0;
	mm['L'] = 1;
	mm['S'] = 2;
	mm['O'] = 3;
	while (scanf("%d%d%d", &n, &m, &s) > 0) {
		res = 0;
		v.clear();
		if (n + m + s == 0)
			return 0;
		for (int i = 0; i < n; i++) {
			cin >> ss;
			v.push_back(ss);
			for (int j = 0; j < ss.length(); j++)
				if (ss[j] == 'N' || ss[j] == 'S' || ss[j] == 'L'
						|| ss[j] == 'O') {

					x = i;
					y = j;

					c = mm[ss[j]];
					ss[j]='.';
				}
		}
		cin >> ins;
		calc(0, c);
		printf("%d\n", res);
	}
	return 0;
}


