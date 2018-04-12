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
class SentenceDecomposition {
public:
	string s;
	vector<string> v;
	int dp[55];
	int decompose(string sentence, vector <string> validWords) {
		v=validWords;
		s=sentence;
		mem(dp,-1);
		int res = calc(0);
		cout <<res << endl;
		if(res != oo ) 
			return res;
		return -1;
	}

	int comp(string a , string b) {
		sort(a.begin(),a.end());
		for (int i = 0 ; i<= sz(b)-sz(a) ; i++ ) {
			string t=s.substr(i,sz(a));
			sort(t.begin(),t.end());
			if (t==a)
				return i;
		}

		return -1;

	}
	int ccost(string a , string b){
		string na=a , nb=b;
		sort(na.begin() ,na.end());
		sort(nb.begin() ,nb.end());
		if(na!=nb)
			return -1 ;
		int c=0;
		rep(i,sz(a))
			if(a[i]!=b[i])
				c++;
		return c;
	}

	int calc (int n ) {
		if (n == sz(s) ) 
			return 0 ;
		if(n>sz(s))
			return oo;
		if(dp[n] !=-1)
			return dp[n];

		int res=oo;
		rep(i,sz(v)) {
			//int p = comp(v[i],s) ;
			//if (p != -1 ) 
			{
				int cost = ccost(v[i],s.substr(n,sz(v[i])));
				if ( cost != -1 ) {
					res = min ( res ,calc(n+sz(v[i]))+cost);
				}
			}

		}
		return dp[n]=res;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	SentenceDecomposition a ;
	vector<string > vv;
	vv.pb("xz");
	vv.pb("zz");
	a.decompose("zzzzzx" , vv);
	return 0 ;
}