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

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int path[100000] , v[100000] ,dp[100000] ,pos[100000] ;  ; 
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int a ,  i = 0 ,n=0 , c= 1 , nub  ;

	bool f=false;
	while (scanf("%d", &a)>0  ) 
	{
		if ( a== -1 ) 
			break;

		if ( f ) 
			cout <<endl;
		f=1;
		n=0;
		i=0;
		memset(v,0,sizeof(v) ) ; 
		memset(dp,0,sizeof(dp) ) ; 

		while( true ) 
		{
			if (a == -1 ) break;
			v[i] = a ;
			i++;
			scanf("%d", &a);
		}
		nub=i;; 
		i--;
		while (nub--)
		{
			int x = lower_bound( dp , dp+n , v[i]) - dp ;
			if ( n == x )
				n++;
			dp[x] = v[i] ;
			i--;
		}
		printf("Test #%d:\n", c);
		printf("  maximum possible interceptions: %d\n", n);
		c++;
	}
	return 0;
}


