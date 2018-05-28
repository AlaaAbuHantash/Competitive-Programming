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

int a,b,x,y,z,f,s;
char c ;
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d%c%d",&a,&c,&b);
	b++;
	if (b!=60) {
		z=b;
		f=b/10;
		s=b%10;
		z= s*10+f;
	}
	else {
		a++;
		if ( a == 24 ) {
			a=0;
			b=0;
			z=0;
		}
		else {
			b=0;
			z=0;
		}
	}
	while( a != z ) {
		f=z/10;
		s=z%10;
		b= s*10+f;
		b++;
		if (b!=60) {
			z=b;
			f=b/10;
			s=b%10;
			z= s*10+f;
		}
		else {
			a++;
			if ( a == 24 ) {
				a=0;
				b=0;
				z=0;
			}
			else {
				b=0;
				z=0;
			}
		}
	}
	f=z/10;
	s=z%10;
	b= s*10+f;
	if ( a==0 && b==0)
		printf("0%d:0%d\n", a,b);
	else if ( a <9 )
		printf("0%d:%d\n", a,b);
	else if(b<9)
		printf("%d:0%d\n", a,b);
	else 
		printf("%d:%d\n", a,b);



	return 0 ;
}
