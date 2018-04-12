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
class Lottery { 
public :
	int x,a[2],n1,n2;
	long long n,ress;
	string s,s1,s2,t,r,ss;
	long long dp[105][10];
	vector<string > fr ; 
	vector<pair < long long , string > > p; 
	long long calc (int ind ,int nub) {
		//cout << ind << " " << nub << endl;
		if( nub== n2 ) 
			return 1;
		if ( dp[ind][nub] !=-1)
			return dp[ind][nub];
		long long res = 0 ;
		if (t=="T" && r =="T" )
			for ( int i = ind+1; i<=n1; i++) 
				res+=calc( i, nub+1 );
		else if ( t=="F" && r == "F") 
			for ( int i = 1; i<=n1; i++) 
				res+=calc( i, nub +1 );
		else if ( t=="T" && r == "F") 
			for ( int i = ind; i<=n1; i++) 
				res+=calc( i, nub +1 );
		return dp[ind][nub]=res;
	}
	vector <string> sortByOdds(vector <string> rules) {
		fr.clear();
		p.clear();

		rep(i,sz(rules)) {
			s = rules[i] ; 
			mem(dp,-1);
			x=s.find(":");
			ss=s.substr(0,x);
			for(int i=x+2,j=0; i<sz(s); i++) if(s[i] == ' ' ){ a[j]=i;j++;if ( j == 2)break;}
			s1=s.substr(x+2,a[0]-x-2); n1=atoi(s1.c_str());
			s2=s.substr(a[0]+1,a[1]-a[0]-1);n2=atoi(s2.c_str());
			t=s.substr(a[1]+1 , 1 ) ; 
			r=s.substr(a[1]+3 , 1 ) ; 
			ress=0;
			if (t=="T" && r =="T" )
				ress= calc (0,0) ;
			else if ( t=="F" && r =="T" ){
				ress=1;
				rep(i,n2) {
					ress=ress*n1;
					n1--;
				}
			}
			else
				ress= calc (1,0);
			p.pb(mp(ress,ss));
		}
		sort(p.begin(),p.end());
		rep(i,sz(p)) 
			fr.pb(p[i].second);
		return fr;
	}

};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	return 0 ;
}
