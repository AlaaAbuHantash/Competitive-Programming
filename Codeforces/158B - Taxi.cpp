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

/* You got a dream, you gotta protect it.*/ 

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
int n,x;
int a[5];
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	mem(a,0);
	scanf("%d",&n);
	rep(i,n) {
		scanf("%d",&x) ; 
		a[x]++;
	}
	int res = a[4] ; 
	x = min ( a[3] , a[1] ) ; 
	res+= x + (a[3] - x ) ; 
	a[1]-=x;
	x=a[2]/2;
	res+=x;
	a[2]=a[2]%2 ;
	x = a[2]*2 + a[1] ; 
	res+= x/4; 
	if( x%4 != 0 ) 
		res++;
	printf("%d\n",res);
	return 0 ;
}

