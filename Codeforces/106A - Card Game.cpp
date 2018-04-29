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
/*YOU got a DREAM, YOU gotta protect it. */
#define pb push_back
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	map<char, int> m;
	m['6'] = 1;
	m['7'] = 2;
	m['8'] = 3;
	m['9'] = 4;
	m['T'] = 5;
	m['J'] = 6;
	m['Q'] = 7;
	m['K'] = 8;
	m['A'] = 9;
	string a, b, c;
	cin >> a >> b >> c;
	if ((b[1] == c[1] && m[b[0]] > m[c[0]]) || (a[0] == b[1] && a[0] != c[1]))
		puts("YES");
	else
		puts("NO");
	return 0;
}

