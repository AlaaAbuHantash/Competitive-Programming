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
int n, x ,y, a, b ,c ,d ; 
vector<pair<int , int > >v ;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n); 
	rep(i,n ) {
		scanf("%d%d",&x,&y) ; 
		v.pb(mp(x,y));
	}

	int res=0;
	for (int i= 0 ; i < n ; i++ ) {
		a=0;b=0;c=0;d=0;
		for(int j=0;j<n; j++) {
			if (v[i].first == v[j].first ) {
				if (v[i].second < v[j].second )
					a++ ;
				else if  (v[i].second >v[j].second )
					b++;
			}
			else if ( v[i].second  == v[j].second) {
				if (v[i].first < v[j].first ) 
					c++;
				else if (v[i].first > v[j].first ) 
					d++;
			}
		}
		if (a>=1 && b>=1 && d>=1 && c>=1 ) 
			res++;
	}
	printf("%d\n",res);
	return 0 ;
}