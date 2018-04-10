
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
int t,c;
long long r ; 
string s,temp ;
int check (int ind ,int nub ) {
	temp = s.substr(ind,nub);
	c=0;
	sort(temp.begin(),temp.end());
	for (int i=0;i<sz(temp);i++)
		if (temp[i]-'0' == i ) c++;
	if ( c == sz(temp ) ) 
		return 1;
	return 0;
}
int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t);
	while(t--) {
		cin>>s;
		r=0;
		for (int i=0 ; i < sz(s) ; i++) 
			for (int j= i , k=1 ; j < sz(s) &&k<=10; j++ , k++){
				r+=check(i,k);
			}
			printf("%lld\n",r );
	}
	return 0 ;
}