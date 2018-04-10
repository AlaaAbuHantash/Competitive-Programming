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
int n,x,res;
vector<int>a;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	int t,a,b,c,d ;
	bool f=false;
	scanf("%d",&t);
	while(t--) {
		f=false;
		scanf("%d%d%d%d",&a,&b,&d,&c);
		b = b+c ; 
		if ( b > 12 ){
			b=b-12;
			f=true;
		}
		if (f ) a++;
		a=a+d;
		printf("%d %d\n",a,b);

	}

	return 0 ;
}