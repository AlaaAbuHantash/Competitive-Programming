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
class CasketOfStar {
public : 
	vector <int > a ; 
	int dp[50][50];
	int maxEnergy(vector <int> weight) {
		mem(dp,-1 ) ; 
		a=weight;
		return (	 calc ( 0,sz(weight)-1));
	}
	int calc (int l , int r) {
		if ( l >= r ) 
			return 0 ;
		if ( dp[l][r]!= -1 ) 
			return dp[l][r];
		int res = 0 ; 
		for ( int i = l+1; i<r ; i++ ) 
			res = max ( res , calc ( l,i)+calc (i,r) + (a[l]*a[r]));
		return dp[l][r] = res ; 
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);

	return 0 ;
}