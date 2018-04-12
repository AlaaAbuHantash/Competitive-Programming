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
int dp[1<<13][25][13];
vector<int > v;
class CollectingMarbles {
public :

	int m,n;
	int mask , fr;
	int calc ( int msk , int sum , int ind ) {
		if ( ind == m)  {
			int c=0;
			rep(i,sz(v )) 
				if (( (msk >> i ) & 1 ) ==1 ) 
					c++;
			if ( c > fr) {
				fr = c ;
				//cout << c << endl;
				mask = msk;
			}
			return c;
		}

		if(dp[msk][sum][ind] !=-1)return dp[msk][sum][ind] ;
		int r = 0;
		r = max (r , calc ( msk , 0 , ind +1));
		for (int i = 0 ; i < sz(v) ; i++) {
			if (( (( msk >> i ) & 1 ) != 1 ) && sum + v[i] <= n )  {
				r = max ( r , calc ( msk |  (1<<i) , sum + v[i] , ind ) ) ; 
			}
		}

		return dp[msk][sum][ind]=r; 
	}

	int mostMarbles(vector <int> marblesWeights, int bagCapacity, int numberOfBags) {
		v = marblesWeights;
		fr=0;
		mask = 0;
		mem(dp,-1);
		n = bagCapacity;
		m=numberOfBags;
		int res=0;
		res=calc(mask , 0  , 0 );
		cout <<res<<endl;
		return res;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);

	vector<int > v ; 
	v.push_back(7);
	v.push_back(6);
	v.push_back(6);
	v.push_back(5);
	CollectingMarbles  d ;
	d.mostMarbles(v,12,2);

	return 0 ;
}