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
int t , n ;
string s ; 
int lp[1000005];
void pre() {
	mem(lp,0);
	int x=0; 
	rep(i,sz(s)-1) {
		while( x > 0 && s[i+1] != s[x] ) 
			x= lp[x-1] ; 

		if ( s[i+1]==s[x] ) 
			lp[i+1] =++x;
		else
			lp[i+1]=x;
	}


	for(int i = 1 ; i < sz(s)+1 ; i++)
		if ( i % ( i - lp[i-1] ) == 0  && lp[i-1] ) 
			cout << i << " " << i / (i - lp[i-1]) << endl;

}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	int c =  1 ;
	scanf("%d" , &t) ; 
	while(t--) {
		scanf("%d" , &n) ; 
		cin >> s; 
		printf("Test case #%d\n" , c++) ; 
		pre();
		if( t ) printf("\n");
	}
	return 0 ;
}