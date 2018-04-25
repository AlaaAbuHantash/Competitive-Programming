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
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6

using namespace std;
long long a, b;
int c, n, m, k;
map <pair <long long, pair<int, int > >, long long > dp;
vector < pair <pair< int, long long > , pair < long long, int > > > p;
bool f = 0;
vector<pair<int, long long > > v;
long long calc(int ind, long long  pre, int cnt){
	//cout << ind << " " << pre << " " << cnt << endl;
	if (cnt == n){
		f = 1;
		return 0;
	}
	
	if (dp.find(mp(pre, mp(ind, cnt))) != dp.end())
		return dp[mp(pre, mp(ind, cnt))];
	long long r = -2e14; 

	for (int i = ind; i < m; i++){
		if (p[i].first.first <= p[ind - 1].first.first)
			continue;
		if ((p[i].first.second <= pre * k && p[i].second.first >= k * pre)
			|| (p[i].first.second <= pre + k && p[i].second.first >= k + pre)){

			if (p[i].first.second <= pre * k && p[i].second.first >= k * pre)
				r = max(r, calc(i + 1, pre * k, cnt + 1) + (pre*k));

			if (p[i].first.second <= pre + k && p[i].second.first >= k + pre)
				r = max(r, calc(i + 1, pre + k, cnt + 1) + (pre + k));
		}
	}
	return dp[mp(pre, mp(ind, cnt))]=r;
}
void pth(int ind, long long  pre, int cnt){
	if (cnt == n)
		return ;

	long long r = -2e14 ,rr = 2e14,gg=0;
	int x;
	for (int i = ind; i < m; i++){
		if (p[i].first.first <= p[ind - 1].first.first)
			continue;
		if (p[i].first.second <= pre * k && p[i].second.first >= k * pre){
			rr = calc(i + 1, pre * k, cnt + 1) + (pre*k);
			if (rr > r){
				r = rr;
				gg = pre*k;
				x = i;
			}
		}

		if (p[i].first.second <= pre + k && p[i].second.first >= k + pre){
			rr = calc(i + 1, pre + k, cnt + 1) + (pre + k);
			if (rr > r){
				r = rr;
				gg = pre+k;
				x = i;
			}
		}

		
	}
	v.push_back(mp(p[x].second.second, gg));
	pth(x + 1, gg, cnt + 1);
}
int  main()
{	
	//freopen("test.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);

	cin >> n >> m >> k; 
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c; 
		p.push_back(mp(mp(c,a), mp(b,i+1)));
	}
	sort(p.begin(), p.end());
	long long res = 0,yy;
	int xx;
	for (int i = 0; i <= m-n; i++){
		for (long long j = p[i].second.first; j >= p[i].first.second; j--){
			if (res <= calc(i + 1, j, 1) + j)
				res = calc(i + 1, j, 1) + j, xx = i, yy = j;
		}
	}
	if (!f)
		puts("NO");
	else
	{
		puts("YES");	
		v.push_back(mp(p[xx].second.second, yy));
		pth(xx + 1, yy, 1);
		for (int i = 0; i < v.size(); i++)
			cout << v[i].first << " " << v[i].second << endl;

	}
	//cout << res << endl;
	return 0;
}