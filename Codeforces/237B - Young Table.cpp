#define _CRT_SECURE_NO_WARNINGS
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
int c[55];
int a[55][55];
map<int, pair < int, int > > p; 
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> c[i]; 

	for (int i = 0; i < n; i++)
		for (int j = 0; j < c[i]; j++){
			cin >> a[i][j]; 
			p[a[i][j]].first = i; 
			p[a[i][j]].second = j;

		}

	int cnt = 1;
	vector<pair<int, int > >res;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < c[i]; j++,cnt++){
			if (a[i][j] != cnt) {
				int aa = p[cnt].first; 
				int bb = p[cnt].second;
				res.push_back(mp(i, j)); 
				res.push_back(mp(aa, bb));
			
				p[cnt].first = i;
				p[cnt].second = j; 
				p[a[i][j]].first = aa; 
				p[a[i][j]].second = bb;
				int tmp = a[aa][bb];
				a[aa][bb] = a[i][j];
				a[i][j] = tmp;
			
			}

	}

	cout << res.size()/2 << endl;
	for (int i = 0; i < res.size(); i += 2)
		printf("%d %d %d %d\n", res[i].first+1, res[i].second+1, res[i + 1].first+1, res[i + 1].second+1);
	return 0;
}