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
#include <cmath>
#include <stdio.h>
#include <string.h>
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int  main()
{

	//freopen("test.in" , "rt" , stdin);

	int t , a , b , c ,co=1;
	scanf("%d",&t);
	char ch , ch2;
	while ( t-- ) 
	{
		scanf("%d %c %d %c %d",&a,&ch,&b,&ch2,&c);
		if ( ch == '+') 
		{
			if ( a+b == c ) 
				printf( "Case %d: YES\n" ,co++  ) ;
			else 
				printf( "Case %d: NO\n" ,co++  ) ;
		}
		else 
		{
			if ( a-b == c ) 
				printf( "Case %d: YES\n" ,co++  ) ;
			else 
				printf( "Case %d: NO\n" ,co++  ) ;

		}

	}
	return 0 ;
}

