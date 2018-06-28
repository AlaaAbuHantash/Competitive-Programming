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
int n,x,m,ind ;
vector <int >a , b;
int  main()
{
	bool g =false;
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	m=oo;
	rep(i,n) {
		scanf("%d",&x) ; 
		a.pb(x);
		b.pb(x);
		if ( x < m ) {
			m = x ; 
			ind = i ; 
			g=false;
		}
		else if ( x > m ) 
			g= true; 
		else if ( x ==m &&g ) {
			g=false;
			m=x;
			ind=i;
		}
	}

	sort(b.begin(),b.end());
	bool f = true;
	for ( int i = ind , j = 0  ; j <sz(b) ; j++ ) {
		if ( a[i]!=b[j] ) {
			f=false ;
			break;
		}
		i++; 
		if ( i == n)
			i=0;
	}
	if ( f ) {
		if ( ind == 0 )
			ind = sz(a);
		printf("%d\n", sz(a) - ind );
	}
	else 
		printf("-1\n");
	return 0 ;
}