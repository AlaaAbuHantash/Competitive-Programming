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
int t, n, m;
string s, pre, a;
vector<int> bb;
void kmpPreprocess() {
	bb.clear();
	bb.resize(m + 10);
	int i = 0, j = -1;
	bb[0] = -1;
	while (i < m) {
		while (j >= 0 && s[i] != s[j])
			j = bb[j];
		i++;
		j++;
		bb[i] = j;
	}
}

int main() {
	//freopen("A.txt", "rt", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &m, &n);
		pre = "";
		int res = m;
		int xx = m ;
		m *= 2;
		m++;

		for (int i = 0; i < n; ++i) {

			if (i == 0) {
				cin >> pre;
				reverse(pre.begin(), pre.end());
				continue;
			}
			cin >> a;
			reverse(a.begin(), a.end());
			s = pre + "@" + a;
			//cout << s << endl;
			kmpPreprocess();
			res += xx - bb[m];
			pre = a;
		}
		printf("%d\n", res);
	}

	return 0;
}
	
