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
int n,m,x;
vector<int > v;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n); 
	int z =0 ,a = 0, b = 0 ;
	rep(i,n){
		scanf("%d",&x ) ; 
		if ( x == 0 ) 
			z++;
		if ( x>0)
			a++;
		if (x<0)
			b++;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	if ( z >= 1 && a>=1 && b >= 1) {
		printf("1 %d\n",v[0] ); 
		printf("1 %d\n",v[n-1] ); 
		printf("%d",sz(v)-2) ; 
		for(int i=1 ; i < sz(v)-1 ; i++ ) 
			printf(" %d",v[i] );
		printf("\n");
	}
	else 	if ( a == 0  && b >=3 ) {
		printf("1 %d\n",v[0] ); 
		printf("2 %d %d\n",v[1] , v[2] ); 
		printf("%d",sz(v)-3) ; 
		for(int i=3; i < sz(v) ; i++ ) 
			printf(" %d",v[i] );
		printf("\n");
	}

	return 0 ;
}