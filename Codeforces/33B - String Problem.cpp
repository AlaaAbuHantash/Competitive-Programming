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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
string a, b;
int dist[26][26];
int d[26];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int c, k;
	cin >> a >> b >> k;
	if (a.length() != b.length()){
		puts("-1");
		return 0;
	}
	char aa, bb;
	vector < vector<pair < int, int > > >v;
	v.resize(26);
	for (int i = 0; i < k; i++){
		cin >> aa >> bb >> c;
		v[aa - 'a'].push_back(mp(bb - 'a', c));
	}
	memset(dist, -1, sizeof(dist));
	for (char i = 0; i < 26; i++){
		priority_queue<pair < int, int > > pq;
		pq.push(mp(0, i));
		dist[i][i] = 0;
		while (!pq.empty()){
			int cur = -pq.top().first;
			int al = pq.top().second;
			pq.pop();
			for (int j = 0; j < v[al].size(); j++){
				int val = v[al][j].second;
				int nalp = v[al][j].first;
				if (val + cur < dist[i][nalp] || dist[i][nalp] == -1){
					dist[i][nalp] = val + cur;
					pq.push(mp(-dist[i][nalp], nalp));
				}
			}
		}

	}

	int res = 0;
	bool f = 1;
	string r = a;
	for (int i = 0; i < a.length() && f; i++){
		if (a[i] != b[i]){
			int x = -1, ind = -1;
			for (int j = 0; j < 26; j++){
				if (dist[a[i] - 'a'][j] != -1 && dist[b[i] - 'a'][j] != -1) {
					if (dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j] < x || x == -1) {
						x = dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j];
						
						ind = j;
					}
				}
			}
			if (x == -1)
				f = 0;
			else{
				res += x;
				r[i] = char(ind + 'a');
			}

		}
	}
	if (f){
		printf("%d\n", res);
		cout << r << endl;
	}
	else
		puts("-1");
	return 0;
}