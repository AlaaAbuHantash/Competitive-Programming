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

/*	You got a dream, you gotta protect it.*/ 

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

int n,m,k,z,x;
string s,temp; 
vector <string > ss ;
int  main()
{
	//freopen("test.in" , "rt" , stdin);

	scanf("%d%d%d",&n,&m,&k);
	m++;
	s="";
	rep(i,n) 
		s+="0";

	rep(i,m){
		scanf("%d",&x);
		temp=s;
		int j=sz(s)-1;
		while(x!=0) {
			z = x %2 ; 
			if (z ==1 ) temp[j] = '1';
			j--;
			x=x/2;
		}

		ss.push_back(temp);
	}

	int c ,res=0;; 
	rep(i,sz(ss)-1) {
		c=0;
		rep(j,n ) 
			if (ss[i][j] != ss[sz(ss)-1][j] ) 
				c++;
		if ( c <= k ) 
			res++;
	}
	printf("%d\n",res);
	return 0 ;
}