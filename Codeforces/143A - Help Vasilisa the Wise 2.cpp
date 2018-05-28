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
int a,b,c,d,e,f;
bool gg;
int  main()
{	
//	freopen("test.in" , "rt" , stdin);
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	gg=false ;
	for (int i =1 ; i<=9 ; i++) {
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				for(int g=1;g<=9;g++) {
					if (i+j==a && k+g ==b&& i+k == c && j+g == d && i+g ==e && j+k ==f   &&  i!=j && i!=k &&i!=g && j!=k && j!=g && k!=g ) {
						printf("%d %d\n" ,i,j);
						printf("%d %d\n" ,k,g);
						gg=true;
					}
				if(gg)break;

				}
				if(gg)break;

			}
			if(gg)break;

		}
		if(gg)break;
	}

	if (!gg)printf("-1\n");
	return 0 ;
}
