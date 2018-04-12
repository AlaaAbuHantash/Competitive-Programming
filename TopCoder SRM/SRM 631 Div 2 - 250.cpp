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
class TaroGrid {
public : 
	int getNumber(vector <string> grid) {
		int w  , b ,  m = 0 ; 
		for (int j=0 ; j <  sz(grid[0] ) ; j++) {
			w=0;b=0;
			for (int i=0; i < sz(grid);i++) {
				if ( grid[i][j] =='W') 
				{
					w++;
					m=max(m,b);
					m=max(m,w);
					b=0;
				}
				else {
					b++;
					m=max(m,w);
					m=max(m,b);
					w=0;
				}
			}
		}

		return m ; 
	}
};

int  main()
{	
	//freopen("test.in" , "rt" , stdin);

	return 0 ;
}