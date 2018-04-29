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
int n,x,d,m,pre,c;
vector<int >a ;

int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n);
	rep(i,n) {
		scanf("%d",&x);
		a.pb(x);
	}
	m=0;
	rep(i,n ) {
		c=0;
		d=a[i] ; 
		pre= a[i];
		for(int j = i ; j < n ; j++) {
			if ( a[j]<=pre) 
				c++;
			else 
				break;
			pre=a[j];
		}
		pre= a[i];
		for ( int j = i-1; j>=0 ;j-- ) {
			if ( a[j]<=pre) 
				c++;
			else 
				break;
			pre=a[j];
		}
		m=max(c,m);
	}
	printf("%d\n",m);
	return 0 ;
}