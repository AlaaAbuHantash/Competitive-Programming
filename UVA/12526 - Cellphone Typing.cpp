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
#include<stdio.h>
#define mp make_pair
#define eps 1e-6

using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s ; 
int n; 
bool f; 
vector<vector < int > > v; 
map < pair<int , int > , int > vis; 
int m,c; 
void calc(){
	int cur = 0, pre; 
	int len = s.length();
	for (int i = 0; i < len; ++i){
		if (f && i> 0){
			if (vis[mp(cur, s[i] - 'a')] != vis[mp(pre, s[i-1] - 'a')])
				c++;
			
		}
		//cout << s[i] << " - " << cur << " " << vis[mp(cur, s[i] - 'a')] << endl;
		//cout << cur << endl;
		if (v[cur][s[i] - 'a'] == -1){
			v.push_back(vector<int >(26, -1));	
			v[cur][s[i] - 'a'] = v.size() - 1;
		
		}
		if (!f)
			vis[mp(cur, s[i] - 'a')]++;
		pre = cur; 
		cur = v[cur][s[i] - 'a']; 

		m = max(m, cur);
	}
}
int  main()
{
	//freopen("A.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	while (scanf("%d", &n) > 0)
	{
		f = 0;
		m = 0;
		v.clear();
		vis.clear();
		v.push_back(vector<int >(26, -1));
		vector<string > r; 
		for (int i = 0; i < n; ++i){
			cin >> s; 
			calc();
			r.push_back(s);
		}
		f = 1; 
		
		int res=0;
		for (int i = 0; i < n; ++i){
			s = r[i]; 
			c = 1;
			calc();
			res += c;
		//	cout << " -- " << endl;
		}
	//	cout << res << endl;
		double g = res / (double )n ; 
		printf("%.2f\n", g);
	}
	
	return 0;
}