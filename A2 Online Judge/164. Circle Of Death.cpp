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

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
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
	int n,t; 
	double p = 3.14159265 , r;
	scanf("%d" , &t ); 
	while(t-- ) 
	{
		scanf("%d" , &n) ;
		r = 2 * p * n ; 
		printf("%.2f\n" , r );
	}

	return 0 ;
}
