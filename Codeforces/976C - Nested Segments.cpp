#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int n, x, y;
	vector<pair<pair<int, int>, int> > v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back( { { x, -y }, i });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {

		if (v[i].first.first >= v[i - 1].first.first
				&& -v[i].first.second <= -v[i - 1].first.second) {
			printf("%d %d\n", v[i].second + 1, v[i - 1].second + 1);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}
