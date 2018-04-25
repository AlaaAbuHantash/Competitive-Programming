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

using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
vector<int> LP ;
int c; 
void prefix (string p ) {
	int len = sz(p ) ; 
	LP.clear();
	LP.resize(len+1);
	int x = 0 ; 
	LP[0]=0;
	rep(i,len){
		while(x>0 && p[i+1] != p[x] ) 
			x = LP[x-1] ; 

		if (p[x] == p[i+1] )
			LP[i+1]=++x;
		else
			LP[i+1]=x;
	}

}
void KMP (string s , string p ) {
	int lens = sz(s) ;
	int lenp = sz(p);
	int x = 0 ;
	rep(i,lens) {
		while(x>0 && s[i] != p[x] ) 
			x = LP[x-1];

		if ( s[i] == p[x] ) 
			x++;

		if ( x == lenp) {
			//printf("%d\n" ,  i - lenp + 1);
			c++;
			x = LP[x-1];
		}
	}

}

int  main()
{
		//freopen("test.in" , "rt" , stdin);
	string s1,s2 ; 
	int res = 0 ; 
	bool f = false;
	while(cin >> s1 ) {
		if(s1==".")break;
		prefix (s1) ;
		if ( sz(s1) %(sz(s1) - LP[(sz(s1))-1] ) != sz(s1) ) 
			printf("%d\n",sz(s1) / (sz(s1) - LP[(sz(s1))-1] ) );
		else
			printf("1\n");

	}
	return 0 ;
}