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
// -matches will contain between 1 and 10 elements, inclusive.
//-Each element of matches will be between 1 and 50, inclusive.
class MatchNumbersEasy{
public :

	string dp[55][11];
	int siz;
	vector <int> m;
	int f;

	bool cstring(string  s1 , string s2){
		rep(i,sz(s1))
			if(s1[i] == '0'){
				s1 = s1.substr(1);
				i=-1;
			}
			else 
				break;


		rep(i,sz(s2))
			if(s2[i] == '0'){
				s2 = s2.substr(1);
				i=-1;
			}
			else 
				break;

		if(sz(s1) > sz(s2) )
			return 1;
		else if( sz(s1) < sz(s2))
			return 0 ;
		else 
			rep(i,sz(s1)){
				if(s1[i] > s2[i])
					return 1 ;
				else if (s1[i] == s2[i] )
					continue;
				else 
					return 0;

		}

		return 1;
	}
	string fun (int r, int x) {
		f=0;
		string res ="",t="" , sol="";

		rep(j,siz){
			if ( r < m[j] ) 
				f++;
		}

		if(f==siz || r==0){
			return "";

		}




		if(dp[r][x] != ".")
			return dp[r][x];

		for ( int i=0;i<siz;i++) {
			if(r-m[i]>=0){
				t=char(i +'0');
				sol=fun(r-m[i], i)+t;
				if(cstring(sol,res))
					res=sol;

			}

		}

		return	dp[r][x]=res;

	}

	string maxNumber(vector <int> matches, int n){
		siz=sz(matches);
		m=matches;
		rep(i,52)
			rep(j,10)
			dp[i][j]=".";

		string res1=fun(n,0),fres;
		f=false;
		fres = res1;
		
		rep(i,sz(res1))
			if(res1[i]=='0')
				fres=res1.substr(i+1);
			else 
				break;

			if(sz(fres)==0)
				fres="0";
			cout << fres <<endl;
			return fres;
	}

};
int  main()
{
	//freopen("test.in" , "rt" , stdin);

	vector<int>v;
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	MatchNumbersEasy m;
	m.maxNumber(v,21);

	return 0 ;
}