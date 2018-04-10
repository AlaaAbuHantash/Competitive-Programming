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
int t,n,x,c;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		c=0;
		rep(i,n){
			scanf("%d",&x);
			if (x==1 || x==0)
				c++;
		}
		if ( c != n ) 
			printf("ambiguous\n");
		else 
			printf("not ambiguous\n");
	}
	return 0 ;
}