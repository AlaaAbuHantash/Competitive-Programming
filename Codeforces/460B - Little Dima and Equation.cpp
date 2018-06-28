
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
int a,b,c,x,xx,z;
vector<int > v;
int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	cin >>a >> b >> c;
	for ( int i =1 ; i <=82;i++) {
		if ( a==1 )
			x=b*(pow(i,1.0)) + c;
		else if ( a==2 ) 
			x=b*(pow(i,2.0)) + c;
		else if ( a==3 ) 
			x=b*(pow(i,3.0)) + c;
		else if ( a==4 ) 
			x=b*(pow(i,4.0)) + c;
		else if ( a==5 ) 
			x=b*(pow(i,5.0)) + c;
		xx= x; 
		z=0;
		while (1 ) {
			z=z+(xx%10);
			xx=xx/10;
			if ( xx == 0 ) 
				break;
		}
		if ( x < 1000000000 && x >0)
			if ( z == i ) 
				v.push_back(x);
	}
	cout << sz(v) <<endl;
	if ( sz(v) != 0 ) {
		cout << v[0] ;
		rep(i,sz(v) -1) 
			cout  << " "<< v[i+1];
		printf("\n");
	}
	return 0 ;
}