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
#define mp make_pair
#define eps 1e-6

using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m;
int  main()
{
	map < char, int > p;
	p['q'] = 1;
	p['a'] = 1;
	p['z'] = 1;
	p['w'] = 2;
	p['s'] = 2;
	p['x'] = 2;
	p['e'] = 3;
	p['d'] = 3;
	p['c'] = 3;
	p['r'] = 4;
	p['f'] = 4;
	p['v'] = 4;
	p['t'] = 4;
	p['g'] = 4;
	p['b'] = 4;
	p['y'] = 7;
	p['h'] = 7;
	p['n'] = 7;
	p['u'] = 7;
	p['j'] = 7;
	p['m'] = 7;
	p['i'] = 8;
	p['k'] = 8;
	p[','] = 8;
	p['o'] = 9;
	p['l'] = 9;
	p['.'] = 9;
	p['p'] = 10;
	p[';'] = 10;
	p['/'] = 10;

	//freopen("A.txt", "rt", stdin);

	//freopen ("myfile.txt","w",stdout);
	while (scanf("%d%d", &n, &m) > 0) {
		int k;
		vector<int>v(11);
		map<string, bool > g;
		for (int i = 0; i < n; i++){
			scanf("%d", &k);
			v[k] = 1;
		}
		string s;
		int res = 0;
		vector < string >r;
		for (int i = 0; i < m; ++i){
			cin >> s;
			int len = s.length();
			bool f = 0;
			for (int j = 0; j < len && !f; ++j)
				if (v[p[s[j]]])
					f = 1;
			if (!f){
				if (len > res){
					res = len;
					r.clear();
					r.push_back(s);
					g[s] = 1;
				}
				else if (len == res && !g[s])
					r.push_back(s),g[s]=1;
			}
		}

		res = r.size();
		sort(r.begin(), r.end());
		printf("%d\n", res);
		for (int i = 0; i < res; i++)
			cout << r[i] << endl;
	}

	return 0;
}