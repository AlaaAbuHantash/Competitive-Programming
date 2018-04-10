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
*   You got a dream, you gotta protect it.
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
int dy[] = {0 ,  0 , 2 ,-2 , 2 , 2 , -2 , -2 } ;
int dx[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
int  main()
{   
	int t,n,x; 
	string a,b,s;
	bool f ;
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t);
	rep(i,t) {
		scanf("%d",&n); 
		cin>>a>>b;
		printf("Case %d:\n",i+1);
		rep(j,n){
			cin>>s;
			f=0;
				b[0] = toupper(b[0] ) ;
				a[0] = toupper(a[0] ) ;

			if(a[0]== b[0]  )  {

				rep(k,sz(s)){
				s[k] = toupper(s[k] ) ;
	
					if(s[k] == b[0] ){
						f=1;break;
					}
				}
			}
			if(f || a[0] != b[0] )
				printf("YES\n");

			else 
				printf("NO\n");

		}
	}

	return 0 ;
}

