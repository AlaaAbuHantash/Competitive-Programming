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
string s ;
map<char , int > m;
map<char , int > ::iterator it ;
int t,a;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t);
	while(t--){
		cin>>s;
		a=0;
		m.clear();
		rep(i,sz(s)) {
			m[s[i]]++;
			a=max(a,	m[s[i]] ) ; 
		}

		for (it=m.begin() ; it!=m.end();it++)
			if ( m[it->first]==a){
				printf("%d %c\n",a , it->first);
				break;
			}
	}

	return 0 ;
}