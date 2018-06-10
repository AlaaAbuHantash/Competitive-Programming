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
int n, x,c,res;
int  main()
{	
	int m=oo*2;
	c=0;
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	rep(i,n ) {
		scanf("%d",&x);
		if (x < m ) {
			m=x ; 
			res=i+1;
			c=0;
		}
		else if ( x==m ) {
			c++;
		}
	}
	if (c ==0 ) 
		printf("%d\n",res);
	else 
		printf("Still Rozdil\n");
	return 0 ;
}