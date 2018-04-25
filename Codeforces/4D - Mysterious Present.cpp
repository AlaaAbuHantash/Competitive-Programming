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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dp[5001];
int a, b, n;
vector<pair <pair < int, int >, int> > v;
int calc(int lst){
	
	if (dp[lst] != -1)
		return dp[lst];
	int rr = 0; 
	for (int i = lst + 1; i< v.size(); i++){
		int x = i;
		if (v[x].first.first > v[lst].first.first && v[x].first.second > v[lst].first.second)
			rr = max(rr, calc(x) + 1);
	}
	return dp[lst] = rr;
}
vector<int > res;
void pth(int lst){

	if (lst == -1)
		return;
	int ind = -1 , r2=-1;
	for (int i = lst + 1; i< v.size(); i++){
		int x = i,rr=-1; 
		if (v[x].first.first > v[lst].first.first && v[x].first.second > v[lst].first.second)
			rr = calc(x) + 1;
		if (rr > r2)
			r2 = rr, ind = i;
	}

	res.push_back(v[lst].second);
	pth(ind);
	return;
}
int main() {
	
	//freopen("test.txt" , "rt" , stdin);
	//freopen ("output.txt","w",stdout);
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0, x, y; i < n; i++){
		scanf("%d%d", &x, &y);
		v.push_back(mp(mp(x, y),i+1));
	}

	sort(v.begin(), v.end());
	int r = 0, rres= -1 , ind = -1 ;
	for (int i = 0; i < n; i++){
		if (v[i].first.first > a && v[i].first.second > b){
			r = calc(i);
			if (r > rres){
				rres = r; 
				ind = i;
			}
		}
	}

	
	if (rres == -1)
		puts("0");
	else{
		pth(ind);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
