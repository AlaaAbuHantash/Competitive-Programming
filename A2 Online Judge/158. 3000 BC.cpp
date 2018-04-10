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
string s,temp;
int n , t ,x;
vector<string > v; 
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t);
	getline(cin,s);
	while(t--){
		getline(cin,s);
		x=s.find(" ") ; 
		temp=s.substr(0,x);
		n = atoi(temp.c_str());
		s.erase(0,x+1);
		rep(i,n*n-sz(s) +(19*19)) 
			s+="*";
		v.clear();
		rep(i,n){
			temp=s.substr(i*n , n ) ; 
			v.pb(temp);
		}

		for (int i =  0 ; i < n ; i++) 
			for (int j = i , k = 0 ;j >=0 ; j-- ,k++) 
				cout <<v[k][j] ;
		for (int i = 1 ; i <n ; i++) 
			for (int j = n-1 , k = i ;k<n ; j-- ,k++) 
				cout <<v[k][j] ;
		printf("\n");
	}
	return 0 ;
}