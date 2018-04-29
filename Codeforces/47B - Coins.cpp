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
string x,y,z;
int a[3];
vector<pair<int , int > > v;
int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	cin >> x >> y >> z ; 
	if (x[1] =='<' ) {
		a[x[0]-'A'] = 1 ; 
		a[x[2]-'A'] = 2 ; 
	}
	else {
		a[x[0]-'A'] = 2 ; 
		a[x[2]-'A'] = 1 ; 
	}

	if (y[1] =='<' ) {
	//	a[y[0]-'A'] = 1 ; 
		a[y[2]-'A']++ ; 
		a[y[2]-'A']++ ; 

	}
	else {
		a[y[0]-'A']++ ; 
		a[y[0]-'A']++ ; 

	//	a[y[2]-'A'] = 2 ; 
	}	
	if (z[1] =='<' ) {
		//a[z[0]-'A'] = 1 ; 
		a[z[2]-'A']++ ; 
		a[z[2]-'A']++ ; 

	}
	else {
		a[z[0]-'A']++ ; 
		a[z[0]-'A']++ ; 

	//	a[z[2]-'A'] = 2 ; 
	}

	//cout << a[0] <<  " " << a[1] << " " << a[2] << endl;
	if ( a[0] == a[1 ] || a[1] == a[2] || a[2]==a[0] ) 
		printf( "Impossible\n");
	else {
		v.push_back(mp(a[0],'A'));
		v.push_back(mp(a[1],'B'));
		v.push_back(mp(a[2],'C'));
		sort(v.begin(),v.end());
		printf("%c%c%c\n",v[0].second,v[1].second,v[2].second);
	}
	return 0 ;	
}