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

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
int t , n , a , b  , c ;
double x , d ; 
vector<pair < int , pair <int , int > > > v ; 
bool vis[100][100];
void BFS () 
{
	//strat  25  0 --- end 25 50
	mem(vis,0);
	queue<pair < int , pair<int ,int  > > > q ; 
	pair<int , pair < int , int> > fr;
	q.push(mp(0, mp(25,0) ));
	int lev = 1 ; 
	bool f= false;
	while(!q.empty() ) {
		int siz = sz(q) ; 
		while (siz-- ) {
			fr=q.front();
			q.pop() ; 
			int a1 = fr.second.first , b1  = fr.second.second; 
			x = sqrt( ( abs ( 25 -a1 )  *  abs ( 25 -a1 ) ) + ( abs(50 - b1 )* abs(50 - b1)) );
			if (x<=d) {
				f=true;
				printf("%d\n" , lev ) ; 
				break;
			}
			rep(i,sz(v)){
				if ( !vis[fr.first][v[i].first] ) 
				{
					a = v[i].second.first ;
					b = v[i].second.second;
				    x = sqrt( ( abs ( a -a1 )  *  abs ( a -a1 ) ) + ( abs(b - b1 )* abs(b - b1)) ); 
				    //cout << x <<endl;
					if ( x <= d ) {
						vis[fr.first][v[i].first]= 1 ; 
						//cout << a << "  " << b << " -- " << a1 << " " << b1 << " x " << x << endl;
						q.push(mp(v[i].first ,mp(a,b))) ; 

					}
				}
			}
		}
		if( f) 
			break;
		lev++;
	}
	if (!f ) 
		printf("Impossible\n");


	while(!q.empty() )
		q.pop();

}
int main() {

	//freopen("test.in" , "rt" , stdin);
	scanf("%d" , &t ) ;
	while(t--) {
		v.clear();
		c=1;
		cin>>d;
		scanf("%d",&n) ; 
		rep(i,n)  {
			scanf("%d%d" , &a,&b) ; 
			v.pb(mp ( c ,mp(a,b ))) ;
			c++;
		}

		BFS();
	}


	return 0;
}


 // ********** husam code " sanfori " :D 
/*

#include <bits/stdc++.h>
using namespace std;
 
#define oo 1e9
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(A) int(A.size())
#define pii pair<int,int>
#define RALL(A) A.rbegin(),A.rend()
#define ALL(A) A.begin(),A.end()
#define rep_(A,B,C) for(int A=B;A>=C;--A)
#define rep(A,B,C) for(int A=B;A<C;++A)
#define rsz(A,B) A.resize(B
#define cl(A) A.clear()
#define mem(A,B) memset(A,B,sizeof A)
#define pdd pair<double,double>
 
typedef long long int lli;
 
int dx[] = {0,0,1,-1,1,-1,1,-1} , dy[] = {1,-1,0,0,1,-1,-1,1};
 
double dist ( const pdd & f , const pdd & s ){
	double a = f.F - s.F;
	double b = f.S - s.S;
	return sqrt(a*a+b*b);
}
 
int main (){
 
#ifndef ONLINE_JUDGE
    freopen("read.txt","r",stdin);
//  freopen("out.txt","w",stdout);
#endif
 
    int t;
    scanf("%d",&t);
    while ( t-- ){
    	double d;
    	int n;
    	scanf("%lf %d",&d,&n);
    	vector<pdd> v(1,mp(25,0));
    	rep ( a , 0 , n ){
    		double x , y;
    		scanf("%lf %lf",&x,&y);
    		v.pb(mp(x,y));
    	}
    	v.pb(mp(25,50));
    	vector<vector<int> >g(n+2,vector<int>(n+2,oo));
    	rep ( a , 0 , sz(v) ) rep( b , a + 1 , sz(v) ){
    		double dif = dist ( v[a] , v[b] );
    		if ( dif <= d || fabs(dif-d) <= 0.0000001 ){
    			g[a][b] = g[b][a] =1;
    		}
    	}
    	rep ( a , 0 , n + 2 ) rep ( b , 0 , n + 2 ) rep ( c , 0 , n + 2 ){
    		g[b][c] = min(g[b][c],g[b][a]+g[a][c]);
    	}
    	if ( g[0][n+1] == oo ){
    		puts("Impossible");
    		continue;
    	}
    	printf("%d\n",g[0][n+1]);
    }
    return 0;
}


*/