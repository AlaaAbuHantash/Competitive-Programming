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
int t , n ,m,x,c,f;
vector<int > a,vis;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ; 
	while(t-- ) {
		scanf("%d%d",&n,&m) ;
		c=0;
		vis.clear();vis.resize(n);
		a.clear();
		rep(i,n ) {
			scanf("%d",&x); 
			a.pb(x);
		}
		int i = 0 ;
		while(c!=n) {
			a[i] = a[i] - m ; 
			if ( !vis[i]){
				if ( a[i] <= 0 ) {
					vis[i] =1 ; 
					c++;
				}
			}
			i++;
			f=i;
			if(i==n)
				i=0;
		}
		printf("%d\n",f);
	}
	return 0 ;
}