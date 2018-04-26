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
vector<int> a;

map<string, bool> vis;
map<string, string> v;
void bfs() {

	vector<int> aa, tmp;
	for (int i = 1; i <= 9; i++)
		aa.push_back(i);
	string cc = "";
	queue<vector<int> > q;
	q.push(aa);
	string s = "", g;
	for (int i = 0; i < 9; i++)
		s += aa[i] + char('0');
	vis[s] = 1;
	v[s] = "";
	while (!q.empty()) {
		s = "";
		aa = q.front();
		q.pop();
		for (int i = 0; i < 9; i++)
			s += aa[i] + char('0');
		tmp = aa;
		tmp[0] = aa[1];
		tmp[1] = aa[2];
		tmp[2] = aa[0];
		g = "";
		for (int i = 0; i < 9; i++)
			g += tmp[i] + char('0');
		if (!vis[g]) {
			cc = v[s];
			cc = "H1" + cc ;
			vis[g] = 1;
			v[g] = cc;
			q.push(tmp);
		}

		tmp = aa;
		tmp[3] = aa[4];
		tmp[4] = aa[5];
		tmp[5] = aa[3];
		g = "";
		for (int i = 0; i < 9; i++)
			g += tmp[i] + char('0');
		if (!vis[g]) {
			cc = v[s];
			cc = "H2" + cc ;
			v[g] = cc;
			vis[g] = 1;
			q.push(tmp);
		}

		tmp = aa;
		tmp[6] = aa[7];
		tmp[7] = aa[8];
		tmp[8] = aa[6];
		g = "";
		for (int i = 0; i < 9; i++)
			g += tmp[i] + char('0');
		if (!vis[g]) {
			cc = v[s];
			cc = "H3" + cc ;
			vis[g] = 1;
			v[g] = cc;
			q.push(tmp);
		}

		//col;
		tmp = aa;
		tmp[0] = aa[6];
		tmp[3] = aa[0];
		tmp[6] = aa[3];
		g = "";
		for (int i = 0; i < 9; i++)
			g += tmp[i] + char('0');
		if (!vis[g]) {
			cc = v[s];
			cc = "V1" + cc ;
			vis[g] = 1;
			v[g] = cc;
			q.push(tmp);
		}

		tmp = aa;
		tmp[1] = aa[7];
		tmp[4] = aa[1];
		tmp[7] = aa[4];
		g = "";
		for (int i = 0; i < 9; i++)
			g += tmp[i] + char('0');
		if (!vis[g]) {
			cc = v[s];
			cc = "V2" + cc ;
			vis[g] = 1;
			v[g] = cc;
			q.push(tmp);
		}
		tmp = aa;
		tmp[2] = aa[8];
		tmp[5] = aa[2];
		tmp[8] = aa[5];
		g = "";
		for (int i = 0; i < 9; i++)
			g += tmp[i] + char('0');
		if (!vis[g]) {
			cc = v[s];
			cc = "V3" + cc ;
			vis[g] = 1;
			v[g] = cc;
			q.push(tmp);
		}
	}

}
int main() {
	//freopen("A.txt", "rt", stdin);
	a.clear();
	a.resize(11);
	bfs();
	while (scanf("%d", &a[0]) > 0) {
		if (!a[0])
			return 0;
		for (int i = 1; i < 9; i++)
			scanf("%d", &a[i]);

		string ss = "";
		for (int i = 0; i < 9; i++)
			ss += a[i] + char('0');
		if (vis[ss]) {
			int len = v[ss].size() / 2;
			printf("%d ", len);
			cout << v[ss];
			puts("");
		} else
			puts("Not solvable");
	}
	return 0;
}

