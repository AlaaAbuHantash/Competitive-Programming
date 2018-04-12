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





class NumberofFiboCalls {
public:
	pair <int , int >  dp[42];
	vector <int> fiboCallsMade(int n) {
		mem(dp,-1);
		pair <int ,int >  p = coaz(n);
		vector<int > v; 
		v.push_back(p.first);
		v.push_back(p.second);

		cout << v[0] << " " << v[1] << endl;
		return v;
	}
	pair <int ,int >  coaz(int i) {
		if (i==1)
			return mp(0,1)  ; 
		if(i==0)
			return  mp(1,0) ;

		if(dp[i].second != -1 && dp[i].second != -1 ) 
			return dp[i];

		int a = coaz (i-1 ).first + coaz( i-2).first;
		int b = coaz (i-1 ).second+ coaz( i-2).second;
		//int c = coaz (i-1 ).first + coaz( i-2).first;
		return dp[i] = mp(a,b);
	}

};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	NumberofFiboCalls  m ; 
	m.fiboCallsMade(22);
	return 0 ;
}