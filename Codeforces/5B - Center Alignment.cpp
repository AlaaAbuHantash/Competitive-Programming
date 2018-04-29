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
string s ; 
vector<string > a ;
int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	int m=0,x,y;
	while(getline(cin,s) ) {
		a.push_back(s);
		m=max(m,sz(s));
	}
	rep(i,m+2) 
		printf("*");
	printf("\n");
	bool f = true;
	for (int i=0;i<sz(a); i++ ) {
		printf("*");
		x=m-sz(a[i]);
		if (x%2 == 0 ) {
			x=x/2;
			y=x;
			for (int j=0; j < x ; j++)
				printf(" " ) ;
		}
		else if ( f ) {
			x=x/2;
			y=x+1;
			f=false;
			for (int j=0; j < x ; j++)
				printf(" " ) ;
		}
		else if ( !f) {
			y=x/2;
			x=(x/2)+1;
			f=true;
			for (int j=0; j < x ; j++)
				printf(" " ) ;
		}
		cout <<a[i]; 
		for (int j=0 ; j <y; j++)
			printf(" " ) ; 
		printf("*\n");
	}

	rep(i,m+2) 
		printf("*");
	printf("\n");
	return 0 ;	
}