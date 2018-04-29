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
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

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
int adj[50][50], mat[50][50];
int n,a,b,m,c;
int  main()
{
	c=0;
	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d",&n) >0) {
		if(!n)break;
		mem(adj,0);
		mem(mat,0);
		m=0;

		rep(i,n) {
			scanf("%d%d", &a,&b);
			adj[a][b]=1;
			m=max(m,max(a,b));
		}

		rep(k,m+1)
			rep(i,m+1)
			rep(j,m+1){
				adj[i][j]+=( (adj[i][k]>=1 && adj[k][j] >= 1 ) ? adj[k][j]*adj[i][k] :0 ); 
		}


		rep(k,m+1)
			if (adj[k][k]>=1)
				rep(i,m+1)
				rep(j,m+1){
					adj[i][j]=(adj[i][k]>=1 && adj[k][j] >= 1 || adj[i][k]==-1 && adj[k][j] >= 1 || adj[i][k]>=1 && adj[k][j] ==-1 ||adj[i][k]==-1 && adj[k][j] ==-1 ) ? -1:adj[i][j]; 
			}

			printf("matrix for city %d\n",c++);

			rep(i,m+1) {
				rep(j,m+1)
					if(j!=m)
						printf("%d ",adj[i][j] );
					else 
						printf("%d",adj[i][j] );
				printf("\n");

			}

	}
	return 0 ;
}

