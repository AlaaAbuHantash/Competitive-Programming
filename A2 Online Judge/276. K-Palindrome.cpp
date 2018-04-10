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

/* You got a dream, you gotta protect it.*/ 

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

int t,n;
string s ;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ;
	while(t--) {
		cin >> n>> s ; 
		int m[30];
		mem(m,0);
		rep(i,sz(s) ) {
			m[s[i]-'a']++;
		}

		int c=0,b=0;
		for (int i = 0 ; i <26 ;i++) 
			if (m[i]!=0){
				if (m[i]%2 == 0 ) 
					c+=(m[i]/2);
				else {
					if (m[i] != 1 )
						c+=((m[i]-1)/2);
					b++;

				}
			}

			bool f=0;
			if ( n == 1 ) {
				if (b <= 1 ) 
					f=1 ; 
			}
			else {
				if ( (b < n && n-b <= c*2 ) || b == n ) 
					f=1;
			}
			if (f)
				printf("YES\n");
			else 
				printf("NO\n");

	}
	return 0 ;
}

