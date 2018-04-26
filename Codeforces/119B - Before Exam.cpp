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

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[100005];
int  main()
{
	//freopen("test.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, k, q, a, b;
	cin >> n >> k;
	vector<int> v, vv;
	for (int i = 0; i < n; i++){
		cin >> a;
		v.push_back(a);
	}
	cin >> q;
	int x = n / k;
	vector<int>res;
	for (int i = 0; i < q; i++){
		int sum = 0;
		for (int j = 0; j < x; j++){
			cin >> a;
			vis[a - 1] = 1;
			sum += v[a-1];
		}

		res.push_back(sum);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			vv.push_back(v[i]);		
	}
	
	sort(vv.begin(), vv.end());
	int z = n - (k *(n / k));

	if (vv.size()-z >= x){
		int sum = 0,ss=0;
		for (int i = 0,j=vv.size()-1; i < x; i++,j--){
			sum += vv[i];
			ss += vv[j];
		}
		
		res.push_back(sum);
		res.push_back(ss);
	}
	sort(res.begin(), res.end());
	if (res.size() == 1)
		res.push_back(res[0]);
	printf("%.6lf %.6lf\n", (double)res[0] / (double)x, (double)res[res.size()-1] / (double)x);
	return 0;
}