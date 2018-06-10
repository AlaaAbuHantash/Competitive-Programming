#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
vector<int> x, y;
vector<pair<pair<int, int>, int> > v;
char s[1000000 + 5];
int main() {

	//freopen("input", "rt", stdin);
	int n;
	long long a, b;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(mp(mp(a, b), i));
	}
	sort(v.begin(), v.end());
	a = 0;
	b = 0;
	for (int i = 0, j = n - 1; i < v.size() && j >= i;) {
		//cout << i << " " << j << " " << a << " " << b << endl;
		if (a == b) {
			if (v[j].first.second > v[i].first.first) {
				a += v[i].first.first;
				s[v[i].second] = 'A';
				i++;

			} else {
				b += v[j].first.second;
				s[v[j].second] = 'G';
				j--;
			}

		} else if (abs(a - (b + v[j].first.second)) <= 500) {
			b += v[j].first.second;
			s[v[j].second] = 'G';
			j--;

		} else {
			a += v[i].first.first;
			s[v[i].second] = 'A';
			i++;
		}

	}

	if (abs(a - b) <= 500) {
		for (int i = 0; i < n; i++)
			cout << s[i];
		puts("");
	} else
		puts("-1");

	return 0;
}

