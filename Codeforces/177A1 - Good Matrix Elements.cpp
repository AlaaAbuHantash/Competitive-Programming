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
int n,x,sum;
int  main()
{
	freopen("test.in" , "rt" , stdin);
	sum=0;
	scanf("%d",&n) ;
	for(int i = 0 ; i < n ; i++) 
		for(int j = 0 ; j < n ; j++) {
			scanf("%d",&x);
			if (i==j)sum+=x;
			else if (i == n/2 )sum+=x;
			else if ( j==n/2) sum+=x;
			else if ( j+i==n-1 ) sum+=x;
		}
		printf("%d\n",sum);
	return 0 ;
}