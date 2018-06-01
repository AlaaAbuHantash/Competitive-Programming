#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<int> freq;
vector<vector<int> > v;
void add(string s) {
	int cur = 0;
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		int ch = s[i] - 'a';
		if (v[cur][ch] == -1) {
			v.push_back(vector<int>(26, -1));
			freq.push_back(0);
			v[cur][ch] = v.size() - 1;
		}
		cur = v[cur][ch];
		freq[cur]++;
	}
}
int calc(int cur, int r) {
	if (freq[cur] == 1)
		return r;
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (v[cur][i] != -1)
			sum += calc(v[cur][i], r + 1);
	}
	return sum;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		freq.clear();
		freq.push_back(0);
		v.clear();
		v.push_back(vector<int>(26, -1));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			add(s);
		}
		printf("%d\n", calc(0, 0));

	}
	return 0;
}
