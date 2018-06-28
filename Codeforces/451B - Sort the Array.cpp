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
int n, x , c , s , e ,cc,z; 
vector<int > a,b,v;
bool f,ff; 
int  main()
{
	freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	rep(i,n ) {
		scanf("%d",&x ) ; 
		a.pb(x); 
		v.pb(x); 

	}
	sort(v.begin() , v.end());
	c=0;
	cc=0;
	z=0;
	s=0;
	f=false;
	ff=false;
	rep(i,sz(a)-1) {
		if ( a[i] > a[i+1] && !f ) {
			f=true; 
			s=i;
			c++;
		}
		else if ( a[i] >a[i+1] && f ) {
			c++;
		}
	}

	for(int i = s ; i <= c+s ; i++){
		b.pb(a[i] ) ; 
	}

	for ( int i = 0 , j = sz(b) -1 ; i <sz(v) ; i++) 
		if ( i >= s && i <= c+s )
		{
			if(b[j] == v[i] ) 
				cc++;
			else 
				break;
			j--;
		}
		else if( a[i] == v[i] ) 
			cc++;

	if ( cc == sz(a)) 
	{
		printf("yes\n");
		printf("%d %d\n",s+1,c+s+1 ) ;

	}
	else 
		printf("no\n");
	return 0 ;
}