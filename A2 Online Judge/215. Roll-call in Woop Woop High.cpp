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
int t,n,a[5],c,r;
string s ,z;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ; 
	r=1;
	while(t--){
		scanf("%d",&n); 
		getline(cin,s) ;
		mem(a,0);
		rep(i,n){
			getline(cin,s) ; 
			istringstream v (s) ; 
			v>>z ; 
			c=0;
			bool f=0;
			while(v >> z ){
				c++; if (z[0] =='y'){ f=true; break;}
			}
			if (c==0 )
				a[3]++;
			else if ( c==1 && f )
				a[0]++;
			else if (f) 
				a[1]++;
			else 
				a[2]++;
		}

		printf("Roll-call: %d\n",r++);
		printf("Present: %d out of %d\n", a[0] , n) ;
		printf("Needs to study at home: %d out of %d\n",a[1],n);
		printf("Needs remedial work after school: %d out of %d\n",a[2],n);
		printf("Absent: %d out of %d\n",a[3],n);
	}
	return 0 ;
}