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
int x,sum; 
string s ; 
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	cin>>s;
	x=0;
	rep(i,sz(s)) {
		x = (x*10+s[i]-'0')%4;
	}

	sum=0;
	if( x%4==3 )
		sum=8+7;
	else if( x%4==0)
		sum=6+1;
	else if( x%4==1)
		sum=2+3;
	else if( x%4==2)
		sum=4+9;
	if(x%2==0)
		sum+=6;
	else 
		sum+=4;

	if (s=="0")
		printf("4\n");
	else 
		printf("%d\n" , (sum+1) %5);


	return 0 ;
}