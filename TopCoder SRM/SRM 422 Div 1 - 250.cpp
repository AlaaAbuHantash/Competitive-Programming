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
*	You got a dream, you gotta protect it.
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
double dp[20][20][20];
bool vis[20];
class PrimeSoccer{
public :
	double x ,y;
	double  calc( int nn , int a , int b ) {
		if ( nn== 18 && ( vis[a] || vis[b] ) ) { 
			//cout << " d " << endl;
			return 1 ; 
		}
		if(nn==18 ) return 0 ;

		double res = 0 ; 
		if ( dp[nn][a][b] != -1 ) 
			return dp[nn][a][b];
		res+= ( x*y ) * calc ( nn+1 , a+1 , b+1 ) ;
		res+= ( x*(1-y) ) * calc ( nn+1 , a+1 , b ) ;
		res+= ( (1-x)*y ) * calc ( nn+1 , a , b+1 ) ;
		res+= ( (1-x)*(1-y) ) * calc ( nn+1 , a, b ) ;

		return dp[nn][a][b]  = res;
	}
	double getProbability(int skillOfTeamA, int skillOfTeamB) {
		vis[2]=1;
		vis[3]=1;
		vis[5]=1;
		vis[7]=1;
		vis[11]=1;
		vis[13]=1;
		vis[17]=1;
		x=skillOfTeamA/100.0;
		y=skillOfTeamB/100.0;
		rep(i,18)rep(j,18)rep(k,18) dp[i][j][k]=-1;
		return calc(0,0,0);
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	//vis[1]=1;


	return 0 ;
}