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
*   You got a dream, you gotta protect it.
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
int dy[] = {0 ,  0 , 2 ,-2 , 2 , 2 , -2 , -2 } ;
int dx[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
int t;
string a ,b;
vector< vector < int > > nxta , nxtb ; 
int dp[81][81];
int ress;
int calc (int x ,int y ) {
	if (x == sz(a ) && y == sz(b) ) 
		return 0;
	if ( x >sz(a)  ||y > sz(b) ) return -oo;
	if (dp[x][y]!=-1)
		return dp[x][y];
	int r = -oo;
	if (a[x]==b[y] ) 
		r = calc ( x+1,y+1)+1;
	return dp[x][y] =max ( max ( calc (x+1, y ) , calc (x , y+1 ) ) , r ) ; 
}
void path (int x , int y , string s  ) {
	if (sz(s) == ress)  {
		cout << s << endl;
		return ;
	}
	//aabc 
	//abc

	for ( int i  =0 ; i < 26 ; i++) {
		int z1 = lower_bound(nxta[i].begin() , nxta[i].end() , x) -nxta[i].begin(); 
		int z2 = lower_bound(nxtb[i].begin() , nxtb[i].end() , y)-nxtb[i].begin() ; 
		if ( z1 < sz(nxta[i])  && z2 < sz(nxtb[i]) ) {			
			if ( calc ( nxta[i][z1] +1, nxtb[i][z2] +1 )+1  == dp[x][y]) {
				path (nxta[i][z1]+1 , nxtb[i][z2]+1 , s + char (i+'a') ) ;
			}
		}  
	}
	
}
int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ; 

	while(t--){
		nxta.clear() ; 
		nxtb.clear() ; 
		nxta.resize(26);
		nxtb.resize(26);
		cin >>a>>b;
		mem(dp,-1);
		ress = calc ( 0 , 0 ) ; 
		rep(i,sz(a )) {
			nxta[a[i]-'a'] .push_back(i) ;
		}
		rep(i,sz(b)) {
			nxtb[b[i]-'a'] .push_back(i) ;
		}
		path(0,0, "");
		if(t)printf("\n");
	}

	return 0 ;
}
