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
#define pi 2 * acos(0);
#define eps 1e-6



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
int n,m,res,b;
int a[12][102],dp[12][102];
vector<int>path;
int minpath(int x , int y) {
	if(y==m)
		return a[x][y];

	if (y>m)
		return oo;

	if(dp[x][y]!=oo)
		return dp[x][y];

	int r1=oo,r2=oo,r3=oo;
	r1=a[x][y] + minpath(x,y+1) ; 

	if (x-1==-1)
		r2=a[x][y] + minpath(n-1,y+1);
	else 
		r2=a[x][y] + minpath(x-1,y+1);

	if(x+1 ==n)
		r3=a[x][y]+ minpath(0,y+1);
	else 
		r3=a[x][y] + minpath(x+1,y+1);

	return dp[x][y] = min(r1,min(r2,r3));
}

void buildpath(int x , int y) {
	if(y==m-1)
		return ;

	int r1=oo,r2=oo,r3=oo;
	int r=oo;

	if (y>m)
		return ;
	r1=a[x][y]+ minpath(x,y+1) ; 

	if (x-1==-1)
		r2=a[x][y] + minpath(n-1,y+1);
	else 
		r2=a[x][y] + minpath(x-1,y+1);

	if(x+1 == n)
		r3=a[x][y] + minpath(0,y+1);
	else 
		r3=a[x][y] + minpath(x+1,y+1);

	r = min ( r1,min(r2,r3));

	 if (r == r3 && x+1 == n) {
		path.pb(0);
		buildpath(0,y+1);
		return ;
	}
	else if (r==r2  && x-1!=-1){
		path.pb(x-1);
		buildpath(x-1,y+1);
		return;
	}

	else if (r == r1 ){
		path.pb(x);
		buildpath(x,y+1);
		return ;
	}
	else if (r == r3 ) {
		path.pb(x+1);
		buildpath(x+1,y+1);
		return ;
	}
	else if (r==r2 && x-1==-1 ){
		path.pb(n-1);
		buildpath(n-1,y+1);
		return ;
	}
}
int  main()
{

	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d%d",&n,&m)>0){
		path.clear();
		mem(dp,0);
		mem(a,0);
		rep(i,n)
			rep(j,m){
				scanf("%d",&a[i][j]);
				dp[i][j]=oo;
		}
		res=oo;
		rep(i,n){
			if (minpath(i,0) < res ) {
				res = minpath(i,0);
				b=i;
			}
		}
		buildpath(b,0);
		printf("%d",b+1);
		rep(i,sz(path))
			printf(" %d",path[i]+1);
		printf("\n");
		printf("%d\n",res);

	}
	return 0 ;
}