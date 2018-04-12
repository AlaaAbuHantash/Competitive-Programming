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

/*  You got a dream, you gotta protect it.*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6
using namespace std;
int dx[]={-1, -1,0, 1,1 ,1,0,-1};
int dy[]={0, 1,1 ,1, 0,- 1,-1,-1};
int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}

class InfiniteSequence {
public :
	int pp,qq;
	map < long long , long long  > dp;
	long long calc2 ( long long x ) {
		if ( x == 0 ) 
			return 1 ; 
		if ( dp.count(x) ) 
			return dp[x];
		return dp[x]=calc2( x / pp ) + calc2( x/ qq ) ; 
	}
	long long calc(long long n, int p, int q) {
		pp=p;
		qq=q;
		return calc2(n);
	}

};
int  main()
{

	//freopen("test.in" , "rt" , stdin);


	return 0 ;
}