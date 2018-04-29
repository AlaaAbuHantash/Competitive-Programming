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
string s,res;
int a,b,c,d,e,x,y,n,sum,ss;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n);
	ss=-oo;
	rep(i,n) {
		cin>>s; 
		sum=0;
		scanf("%d%d%d%d%d%d%d",&x,&y,&a,&b,&c,&d,&e);
		if(a>=150&& a<=500)
			sum+=a;
		if(b>=300&&b<=1000)
			sum+=b;
		if(c>=450&&c<=1500)
			sum+=c;
		if(d>=600&&d<=2000)
			sum+=d;
		if(e>=750&&e<=2500)
			sum+=e;
		sum+= (x*100) + (y*-50);
		if(sum>ss){
			ss=sum;
			res=s;
		}
	}
	cout <<res<<endl;
	return 0 ;
}
