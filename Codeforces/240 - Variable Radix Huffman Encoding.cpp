#define _CRT_SECURE_NO_WARNINGS
// yes !
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

int main() {
	//freopen("a.txt", "rt", stdin);
	int n, r, f, tt = 1, ff;
	while (scanf("%d", &r) > 0) {
		if (!r)
			break;
		ff = 0;
		string res[33] = { }, g = "";
		scanf("%d", &n);
		vector<int> v(n);
		priority_queue<pair<int, string>, vector<pair<int, string> >,
				greater<pair<int, string> > > q;

		for (int i = 0; i < n; i++) {
			scanf("%d", &f);
			ff += f;
			v[i] = f, res[i] = "";
			q.push(mp(f, res[i] + char('A' + i)));
		}

		int rr = 0, tmp;
		while ((rr * (r - 1)) + r < n)
			rr++;

		tmp = ((rr * (r - 1)) + r) - n;

		for (int i = 0; i < tmp; i++)
			q.push(mp(0, g + char('A' - 1)));

		while (q.size() != 1) {
			int siz = q.size(), sum = 0;
			char c = char('0');
			g = "";

			for (int i = 0; i < r; i++) {

				sum += q.top().first;
				string cur = q.top().second;
				if(cur != "@")
				g += cur;

				q.pop();
				for (int j = 0; j < cur.size(); j++)
					res[cur[j] - 'A' + 1] = c + res[cur[j] - 'A' + 1];

				c++;
			}
			sort(g.begin(),g.end());
			q.push(mp(sum, g));

		}
		q.pop();
		double ress = 0;
		for (int i = 1; i <= n; i++)
			ress += v[i - 1] * res[i].size();

		ress /= (double) ff;

		printf("Set %d; average length %.2lf\n", tt, ress);

		for (int i = 1; i <= n; i++)
			printf("    %c: %s\n", char(i + 'A' - 1), res[i].c_str());

		puts("");
		tt++;
	}

	return 0;
}

