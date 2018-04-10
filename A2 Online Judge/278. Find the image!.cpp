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
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	int t; 
	scanf("%d",&t) ;
	while(t--) {
		int a,b,c;
		string s ; 
		vector <string > v,vv;
		scanf("%d%d%d",&a,&b,&c);
		int res=0,rr=0;
		bool ff=1;
		rep(i,a){
			cin >> s ; 
			v.pb(s);
		}
		rep(k,c) {
			vv.clear();
			rep(j,a) {
				cin >> s ; 
				vv.pb(s);
			}
			bool f=1;
			int r = 0 ,z=0; 
			rep(i,a) 
				rep(j,b) {
					if ( vv[i][j] == '*'  ) 
						r++;
					else 	if(vv[i][j] != v[i][j] ) {
						f=0;
					}
					else 
						z++;
			}

			if ( z == a*b) 
				rr++;

			if ( r+z == a*b)
				res++;

		//	cout << rr << " " << res << endl;
		}
		if (rr == 1 ) 
			printf("YES\n");
		else if (res > 1  || res == 0 ) 
			printf("NO\n");
		else 
			printf("YES\n");
	}
	return 0 ;
}

