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
class CuttingBitString {
public :
	string s ;
	int getmin(string S) {
		s=S;
		mem(dp,-1) ; 
		five ();
		int r = calc(0);
		if ( r == oo ) 
			return -1 ; 
		return r ;
	}

	int dp[55];
	bool f ;
	vector<long long int > v ;
	void five () {
		long long int x = 1 ;
		rep(i,22) {
			v.pb(x);
			x*=5;
		}
	}
	bool fun (int a, int b){
		string temp = s.substr(a , b-a+1 ) ; 
		if ( temp[0] == '0' )
			return 0 ; 
		long long int sum=0;
		for (int i = sz(temp)-1,j=0 ; i >=0 ; j++,i--) 
			if(temp[i]=='1')
				sum+=pow(2.0,j);

		rep(i,sz(v)) 
			if(sum==v[i] )
				return 1;
		return 0;
	}

	int calc(int x) {

		if (x==sz(s))
			return 0 ;
		if(x>sz(s))
			return oo;
		if (dp[x]!=-1)
			return dp[x];
		int res=oo;
		for(int i = x ; i<sz(s) ;i++ ) {
			f=fun(x,i);
			if (f)
				res = min(res, 1 + calc(i+1) );
		}
		return dp[x] = res;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	return 0 ;
}