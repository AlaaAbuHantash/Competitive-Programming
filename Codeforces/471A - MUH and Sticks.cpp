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
	vector<int > a;
	int x;
	vector<int > b (2);
	map < int , int > m ; 
	map < int , int > ::iterator it ; 
	rep(i,6) {
		scanf("%d",&x);
		m[x]++;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int nub,f=0,c=0;
	for ( it = m.begin() ; it != m.end() ; it++) {
		if (m[it->first] >= 4 ) {
			nub = it->first;
			f=true;
			break;
		}

	}

	if (!f) 
		printf("Alien\n" );
	else {
		rep(i,6) 
			if ( a[i] == nub && c<4) {
				a[i]=-1;
				c++;
			}

			int j=0;
			rep(i,6) 
				if (a[i] != -1 ) {
					b[j] = a[i];
					j++;
				}
				
				//cout << b[0] << b[1] << endl;
				if (b[0] >= b[1] ) 
					printf("Elephant\n");
				else 
					printf("Bear\n");
	}
	return 0 ;
}

