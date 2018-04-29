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
int n,x,y,d,st;
vector<pair <int , int > > p ;
double dp[10][1<<9],r;
int vis[10];
vector<int>path;
double calc (int a, int nub) {
	if(nub == (1<<n)-1)
		return 0;

	if(dp[a][nub] != -1 ) 
		return dp[a][nub] ;

	double res =oo;
	rep(i,n) {
		if ( ( ( nub>> i) & 1 ) == 1 )
			continue;
		double c = sqrt(abs((p[a].first-p[i].first))*abs((p[a].first-p[i].first)) + abs((p[a].second-p[i].second))*abs((p[a].second-p[i].second)));
		res=min(res,c+16+calc(i,nub|(1<<i)));
	}
	return dp[a][nub]= res;
}
int ab;
void buildpath(int a, int nub) {

	if(nub == (1<<n)-1)
		return ;

	double res =oo;
	rep(i,n) {
		if ( ( ( nub>> i) & 1 ) == 1 )
			continue;
		double c = sqrt(abs((p[a].first-p[i].first))*abs((p[a].first-p[i].first)) + abs((p[a].second-p[i].second))*abs((p[a].second-p[i].second)));
		double temp = c+16+calc(i,nub|(1<<i));
		if ( temp < res ) {
			res = temp ;
			ab=i;
		}

	}
	path.pb(ab);
	buildpath(ab,nub|(1<<ab));


}
int  main()
{
	int ca=1;
	//freopen("test.in" , "rt" , stdin);
	while (scanf("%d",&n ) >0) {
		if(!n)break;
		p.clear();
		path.clear();

		rep(i,n){
			scanf("%d%d",&x,&y);
			p.pb(mp(x,y));
		}
		double r =oo ;
		printf("**********************************************************\n");
		printf("Network #%d\n",ca++);
		rep(i,n)
			rep(j,1<<9)
			dp[i][j]=-1;
		int st ;
		double rr=oo;
		rep(i,n){
			r = calc (i,0|(1<<i)) ;
			if (r<rr) {
				rr=r;
				st=i;
			}
		}
		path.pb(st);
		buildpath(st,0|(1<<st));
		rep(i,sz(path)-1){
			int a1,a2,a3,a4;
			a1=p[path[i]].first;
			a2=p[path[i]].second;
			a3=p[path[i+1]].first;
			a4=p[path[i+1]].second;
			double aa = sqrt ((a1-a3)*(a1-a3) + (a2-a4)*(a2-a4))+16; 
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", a1,a2,a3,a4, aa);
		}
		printf("Number of feet of cable required is %.2lf.\n",rr);

	}
	return 0 ;
}