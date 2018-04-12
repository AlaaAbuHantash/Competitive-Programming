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
// s = 100 , k = 20 ;
class MaximalProduct{
public :
	int s2,k3;
	long long dp[25][105],fres;
	long long maximalProduct(int s, int k) {
		s2=s;
		k3=k;
		mem(dp,-1);
		fres=-oo;


		fres= fun(s,0);


		//if(k==1)
		//	fres=s;
		//if(s==k)
		//	fres=1;
		//cout <<fres <<endl;
		return fres;
	}

	long long fun ( int r , int k2) {

		//cout << k2 << " " << r << endl;
		if (r == 0 && k2== k3) {
			return 1;
		}
		if(r < 0  || k2 > k3 )
			return -oo;

		long long res = -oo;

		if ( dp[k2][r] !=-1 ) 
			return dp[k2][r] ;

		for(int i =1 ; i <= r ;i++) {
			res= max(res,fun(r-i,k2+1)*(i) );
		}
		return dp[k2][r]= res;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	MaximalProduct m ; 
	int s,k;
	scanf("%d%d",&s,&k);
	m.maximalProduct(s,k);
	return 0 ;
}