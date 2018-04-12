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


class PolygonCover {
public:
	vector<double > x,y;
	double ma,mb;
	vector< vector< pair <int , int > > > p;
	int a[16][16][16];
	double area(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
	}

	bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
	{   
		double A = area (x1, y1, x2, y2, x3, y3);
		double A1 = area (x, y, x2, y2, x3, y3);
		double A2 = area (x1, y1, x, y, x3, y3);
		double A3 = area (x1, y1, x2, y2, x, y);
		return (A == A1 + A2 + A3);
	}
	void istringle () {
		p.clear();
		p.resize(sz(x));
		mem(a,0);
		rep(i,sz(x)) {
			rep(j,sz(y)) {
				rep(k,sz(x) ) {
					if (i != j && i != k  && j!=k) {
						ma= (y[i] - y[j] ) / (x[i]-x[j]) ; 
						mb= (y[k] - y[j] ) / (x[k]-x[j]) ; 

						if (ma==mb) continue;
						int mask = 0;
						p[i].pb(mp(j,k));
						mask = mask | ( 1 << k ) ; 
						mask = mask | ( 1 << i ) ; 
						mask = mask | ( 1 << j) ; 

						rep(g,sz(x)) {
							if(isInside(x[i],y[i],x[j],y[j],x[k],y[k],x[g],y[g] ) ) {
								mask = mask | ( 1 << g) ; 
							}
						}
						a[i][j][k]=mask;
					}
				}
			}
		}
	}
	double dp[1<<15][16];
	double calc ( int msk , int ind ) {
		if(msk==(1<<sz(x))-1 ) 
			return 0.0;
		if ( ind >= sz(y ) ) return oo;
		double res =oo;
		if(dp[msk][ind]!=-1)
			return dp[msk][ind] ;
		rep(i,sz(p[ind] )) {
			if( ( ( (msk >> p[ind][i].first ) & 1 ) == 1 ) &&   ( (msk >> p[ind][i].second ) & 1 ) == 1 &&   ( (msk >> ind) & 1 ) == 1 )  
				continue;
			res = min (res , calc (msk | a[ind][p[ind][i].first][p[ind][i].second], ind) + area(x[ind] ,y[ind] , x[p[ind][i].first] , y[p[ind][i].first] , x[p[ind][i].second] , y[p[ind][i].second] ) ) ;

		}
		res = min (res ,  calc ( msk , ind +1 ) ) ;
		return dp[msk][ind] =res;
	}

	double getArea(vector <int> xx, vector <int> yy) {
		rep(i,sz(xx)){
			x.push_back(xx[i]);
			y.push_back(yy[i]);
		}
		rep(i,sz(x))
			rep(j,1<<15) 
			dp[j][i]=-1;
		istringle();
		return calc(0,0);
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	return 0 ;
}