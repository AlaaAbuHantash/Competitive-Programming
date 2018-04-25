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
#include<set>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int x, y;
string s;
struct ss {
	int a, b, res;
};
vector<ss> st;
void build(int p, int l, int r) {
	if (l == r) {
		st[p].a = 0;
		st[p].b = 0;
		st[p].res = 0;
		if (s[l] == '(')
			st[p].a = 1;
		else
			st[p].b = 1;
		return;
	}

	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, ((l + r) / 2) + 1, r);
	int z = min(st[p * 2].a, st[p * 2 + 1].b);
	st[p].a = st[p * 2].a - z + st[p * 2 + 1].a;
	st[p].b = st[p * 2 + 1].b - z + st[p * 2].b;
	st[p].res = st[p * 2].res + st[p * 2 + 1].res + z;
}
ss get(int p, int l, int r) {
	if (l > y || r < x) {
		ss tmp;
		tmp.a = 0;
		tmp.b = 0;
		tmp.res = 0;
		return tmp;
	}
	if (l >= x && r <= y)
		return st[p];
	ss aa, bb, cc;
	aa = get(p * 2, l, (l + r) / 2);
	bb = get(p * 2 + 1, ((l + r) / 2) + 1, r);
	int z = min(aa.a, bb.b);
	cc.a = aa.a - z + bb.a;
	cc.b = bb.b - z + aa.b;
	cc.res = aa.res + bb.res + z;
	return cc;
}
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int p;
	cin >> s >> p;
	int n = s.length();
	st.clear();
	st.resize(n * 4);
	build(1, 0, n - 1);
	for (int i = 0; i < p; i++) {
		cin >> x >> y;
		x--;
		y--;
		cout << get(1, 0, n - 1).res * 2 << endl;
	}
}


