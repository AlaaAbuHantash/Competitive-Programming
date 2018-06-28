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


int  main()
{
	//freopen("test.in" , "rt" , stdin);
	string s,t;
	bool f = 0 ,f2=0, vis [105];
	int c=0;
	mem(vis,0);
	cin>>s>>t;
	int g=0;
	for ( int i = 0 ; i < sz(t) ; i++ )
		for (int j = g; j < sz(s ) ; j++) {
			if (t[i] == s[j] && !vis[j] ) {
				vis[j]=1;
				c++;
				g=j;
				break;
			}
		}
		if ( c == sz(t))
			f=1;
		if ( f &&sz(s)!=sz(t)) {
			printf("automaton\n");
			return 0;
		}
		mem(vis,0);
		sort(s.begin() , s.end());
		sort(t.begin() , t.end());
		c=0;
		for ( int i = 0 ; i < sz(t) ; i++ )
			for (int j = 0 ; j < sz(s ) ; j++) {
				if (t[i] == s[j] && !vis[j] ) {
					vis[j]=1;
					c++;
					break;
				}
			}

			if( c == sz(t) && sz(t) == sz(s)) f2=1;
			if ( f2) {
				printf("array\n");
				return 0;
			}

			if( c == sz(t) )  printf("both\n");
			else printf("need tree\n");

			return 0 ;
}