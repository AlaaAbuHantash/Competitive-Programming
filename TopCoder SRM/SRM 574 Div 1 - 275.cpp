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
set<string > v;
set<string > ::iterator it ;
class TheNumberGame {
public : 
	int x;
	string temp,ss , r ;
	string s ; 
	string determineOutcome(int A, int B ) {
		s="";ss="";
		while(A!= 0 ) {
			x=A%10;
			s+=('0'+x);
			A=A/10;
		}
		while(B!= 0 ) {
			x=B%10;
			ss+=('0'+x);
			B=B/10;
		}
		r = ss; 
		reverse(r.begin(),r.end());
		bool f = false;
		for (int i = 0 ; i < sz(s) ; i++) {
			if (s[i] == ss[0] ) {
				temp = s.substr(i,sz(ss));
				if( temp == ss ) {
					f=true; 
					break;
				}
			}
			if (s[i] == r[0] ) {
				temp = s.substr(i,sz(r));
				if( temp == r ) {
					f=true; 
					break;
				}
			}
		}
		cout << f <<endl;
		if ( f) 
			return "Manao wins";
		else 
			return "Manao loses";
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	TheNumberGame f ; 
	f.determineOutcome(	456,654 ) ; 

	return 0 ;
}