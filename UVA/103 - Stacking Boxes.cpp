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

/*
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}

int n,d,res,b,cur,a,x,s;
//int v[31][11];
vector<vector<int > > v,org; 
int dp[50][50];
int vis[50];
vector<int>nub,f;
bool check_everything(int a,int b){

	rep(i,d)
		if(v[a][i] <= v[b][i] )
			return false;

	return true;
}
int fun(int x , int l ) {
	//cout << x << " " << l << endl;
	if(x==n)return 0 ; 
	if(dp[x][l]!=-1)return dp[x][l];
	int r=fun(x+1,l);
	if(check_everything(x,l)) 
		r=max(r,fun(x+1,x)+1);

	dp[x][l]=r;
	return r;
}


void tracefun(int x , int l ) {
	if(x==n-1)
	{
		//cout << x << " " << nub[x]+1 << "l " <<nub[l]+1 <<endl;
		if(!vis[nub[x]+1])
			f.pb(nub[x]+1);
		vis[nub[x]+1]=1;
		return ;
	}
	//int r=fun(x+1,l);

	int r1=fun(x+1,l),r2=0,r3;
	if(check_everything(x,l))
		r2=fun(x+1,x)+1 ;

	r3=max(r1,r2);
	if (r3 == r1)
	{
		//cout << x << " " << nub[x]+1 << " l " << l <<" " << nub[l]+1 <<endl;
		if(!vis[nub[l]+1])
			f.pb(nub[l]+1);
		vis[nub[l]+1]=1;
		tracefun(x+1,l);
		return ;
	}
	else 
	{
		//cout << x << " " << nub[x]+1 << " l2 " << x<< " " << nub[x]+1 << endl;
		if(!vis[nub[x]+1])
			f.pb(nub[x]+1);
		vis[nub[x]+1]=1;
		tracefun(x+1,x);
		return;
	}

}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d%d",&n,&d) >0) {
		mem(dp,-1);
		mem(vis,0);
		f.clear();
		v.clear();
		v.resize(n,vector<int>(d,-1));
		nub.clear();
		nub.resize(n);
		res=0;
		rep(i,n)
			rep(j,d)
			scanf("%d",&v[i][j]);

		rep(i,n)
			sort(v[i].begin(),v[i].end());

		org = v ;

		sort(v.begin(),v.end());

		rep(i,n)
			rep(j,n) {
				if(v[i] == org[j]){
					nub[i]=j;
					break;
				}
		}



		rep(i,n){
			x = fun(i+1,i)+1;
			if(res<x){
				res=x;
				s=i;
			}
		}
		vis[nub[s]+1]=1;
		f.pb(nub[s]+1);
		printf("%d\n", res);

		tracefun(s+1,s);
		printf("%d",f[0]);
		rep(i,res-1)
			printf(" %d",f[i+1]);
		printf("\n");
	}
	return 0 ;
}