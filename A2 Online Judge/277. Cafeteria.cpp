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

/* You got a dream, you gotta protect it.*/ 

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
	int t  ; 
	scanf("%d",&t) ; 
	while(t-- ) {
		string s ;
		cin >> s ; 
		int a=0,b=0,c=0;
		bool f=1;
		rep(i,sz(s) ) {
			if( s[i] == 'A' ) {
				a++ ; 
			}
			else if ( s[i] == 'a' &&a ) {
				a--; 
			}
			else if (s[i] == 'a' ) 
				f=false ;
			else if ( s[i] == 'B' ) {
				b++; 
			}
			else if ( s[i] == 'b' && b ){
				b-- ; 
			}
			else if (s[i] == 'b' ) 
				f=false ;
			else if ( s[i] == 'C') {
				c++ ;
			}
			else if ( s[i] == 'c' &&c){
				c--;
			}
			else if (s[i] == 'c' ) 
				f=false ;
		}
		if (a==0 && b==0 && c==0 && f ) 
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0 ;
}

