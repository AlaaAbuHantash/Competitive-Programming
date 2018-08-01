#include <bits/stdc++.h>
using namespace std;
int p[20001];
int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
int main() {
	//freopen("a.txt", "r", stdin);
	string s;
	int ind = 1;
	map<string, int> m;
	vector<string> v;
	while (cin >> s && s != "--") {
		m[s] = ind;
		p[ind] = ind;
		ind++;
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++) {
			int c = 0;
			if (v[i].size() != v[j].size())
				continue;
			for (int k = 0; k < v[i].size(); k++)
				if (v[i][k] != v[j][k])
					c++;
			if (c <= 1)
				p[find(i+1)] = p[find(j+1)];
		}
	string a, b;
	while (cin >> a >> b) {
		if (m[a] && m[b] && find(p[m[a]]) == find(p[m[b]]))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

