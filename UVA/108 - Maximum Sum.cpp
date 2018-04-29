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

/*  You got a dream, you gotta protect it.*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6
using namespace std;
int dx[]={-1, -1,0, 1,1 ,1,0,-1};
int dy[]={0, 1,1 ,1, 0,- 1,-1,-1};
int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
int n ; 
int v[102][102] ; 
int sum[105][105];
int  main()
{
	freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	mem(sum,0);
	mem(v,0);

	for ( int  i= 1; i <= n ; i++) 
		for( int j = 1; j <= n ; j++) 
			scanf("%d",&v[i][j] ) ; 

	int x=0;


	for ( int i = 1 ; i <=n ;i++) {
		x=0;
		for (int j = 1 ; j <=n ; j++) {
			x+=v[i][j] ; 
			sum[i][j]=x + sum[i-1][j]; 
		}
	}

	int res=-oo;
	for (int i=0 ; i <=n ; i++) 
		for(int j = 0; j <= n ; j++) 
			for(int k=i; k <= n ; k++) 
				for(int g =j ; g <= n ; g++) {
					x=sum[k][g] - sum[k][j] - sum[i][g] + sum[i][j] ; 
					//cout << i << " " << j << " " << k << " " << g << " " << x << endl;
					//	cout << sum[k][g] << " " << sum[k][j-1] << " " << sum[i-1][g] << " " << sum[i-1][j-1] << endl;
					res=max(x,res);
				}
				printf("%d\n",res);
				return 0 ;
}
