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

class MessageMess {
public:
	vector <string >v ,r; 
	string s,st;
	long long int dp[55],n;
	string restore(vector <string> dictionary, string message) {
		v=dictionary;
		s=message;
		mem(dp,-1);
		n=calc (0);
		if (n >1 ) 
			return "AMBIGUOUS!";
		else if ( n==1){
			buildpath(0);
			st=r[0];
			rep(i,sz(r)-1)
				st=st+" " +r[i+1];
			return st;
		}
		else 
			return "IMPOSSIBLE!";


	}


	long long int calc (int x ) {
		if (x==sz(s))
			return 1 ; 
		if(x>sz(s))
			return 0;

		if(dp[x]!=-1)
			return dp[x];
		long long int res=0;
		rep(i,sz(v)){
			string temp=s.substr(x,sz(v[i]));
			if(temp == v[i] ) 
				res+=calc(x+sz(v[i]));
		}
		return dp[x]=res;
	}

	void buildpath(int  x) {
		if(x==sz(s))return ; 
		if(x>sz(s))return;

		rep(i,sz(v)){

			string temp=s.substr(x,sz(v[i]));

			if(temp == v[i] ) {
				long long int res=calc(x+sz(v[i]));
				if ( res==1) {
					r.pb(v[i]);
					buildpath(x+sz(v[i]));
					return;
				}
			}
		}
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	MessageMess a ; 
	vector <string >ss ;
	ss.pb("AA");
	ss.pb("A");
	ss.pb("AAA");

	a.restore(ss,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	return 0 ;
}