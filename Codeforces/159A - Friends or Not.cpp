#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
#define mp make_pair
vector<vector<vector<int> > > v;
int vis[1111][1111];
vector<pair<int, int> > p;

int main() {
	//freopen("input", "rt", stdin);
	int n, d, x, c = 1;
	cin >> n >> d;
	string a, b;
	map<string, int> m;
	map<int, string> rm;
	v.resize(n * 3 , vector<vector<int> >(n * 3 ));
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> x;
		if (m[a] == 0) {
			rm[c] = a;

			m[a] = c++;
		}
		if (m[b] == 0) {
			rm[c] = b;
			m[b] = c++;
		}
		v[m[a]][m[b]].push_back(x);
	}
	//cout << c << endl;
	for (int i = 0; i <= n*2; i++) {
		for (int j = i + 1; j <=n*2; j++) {
			bool f = 0;
			for (int k = 0; k < v[i][j].size() && !f; k++) {
				for (int g = 0; g < v[j][i].size() && !f; g++) {
					if (abs(v[i][j][k] - v[j][i][g]) <= d
							&& abs(v[i][j][k] - v[j][i][g]) > 0) {
						f = 1;
						p.push_back(mp(i, j));
					}
				}
			}
		}
	}
	cout << p.size() << endl;
	for (int i = 0; i < p.size(); i++)
		cout << rm[p[i].first] << " " << rm[p[i].second] << "\n";
	return 0;
}

