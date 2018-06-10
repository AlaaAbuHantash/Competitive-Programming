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

int n,m;
long long int r[5],v[5],a[55];

int  main()
{
	mem(r,0);
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	rep(i,n) 
		scanf("%I64d",&a[i]);
	rep(i,5 ){
		scanf("%I64d",&v[i] ) ; 

	}
	
	long long int res=0,sum=0;
	rep(i,n) {
		sum+=a[i];
		for (int j = 4 ; j>=0 ; j--) {
			long long int  x = sum/v[j];
				sum-=(v[j]*x) ;
				r[j]+=x;
		
		}
		//res+=a[i];
	}

	rep(i,5 )
		printf("%I64d ",r[i] ) ; 
	printf("\n");
	printf("%I64d\n",sum);

	return 0 ;
}