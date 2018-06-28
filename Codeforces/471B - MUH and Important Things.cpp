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
int n,x;

vector<int > v,r,rr;
vector<pair<int , int > > vv;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	rep(i,n) {
		scanf("%d",&x);
		v.pb(x);
		vv.pb(mp(x,i));
	}
	sort(v.begin(),v.end());
	sort(vv.begin(),vv.end());
	int c=0,res=0;
	bool f=0;
	int nub = 0;
	rep(i,n-1) {
		if(v[i] == v[i+1] ){
			c++;
		}
		else if ( c >=2 ) {
			f=1;
			nub = v[i];
			c=0;
			break;
		}
		else if ( c>=1 ) {
			rr.pb(v[i]);
			res++;
			c=0;
		}
		else if ( res == 2 ) 
			break;
		else 
			c=0;
	}

		if (v[sz(v)-1] == v[sz(v)-2] && n>=3 ) {
			rr.pb(v[sz(v)-1]);
		}

		if ( c>=2){
			nub=v[sz(v)-1];
			f=1;
		}
		else 	if ( c>=1 ) 
			res++;

		if (f) {  
			printf("YES\n");
			r.clear();
			rep(i,n) 
				if ( vv[i].first == nub ) {
					r.push_back(vv[i].second);
					if ( sz(r) == 3 ) break;
				}

		
				rep(j,n) {
					if(r[0]==vv[j].second) {
						printf("%d %d %d ",vv[j].second+1 ,vv[j+1].second+1 ,vv[j+2].second+1 );
						j+=2;
					}
					else
						printf("%d ",vv[j].second+1);
				}
				printf("\n");

				rep(j,n) {
					if(r[0]==vv[j].second) {
						printf("%d %d %d ",vv[j+1].second+1 ,vv[j].second+1 ,vv[j+2].second+1 );
						j+=2;
					}
					else
						printf("%d ",vv[j].second+1);
				}	
				printf("\n");

				rep(j,n) {
					if(r[0]==vv[j].second) {
						printf("%d %d %d ",vv[j].second+1 ,vv[j+2].second+1 ,vv[j+1].second+1 );
						j+=2;
					}
					else
						printf("%d ",vv[j].second+1);
				}
				printf("\n");

		}

		else if ( res >= 2 ) {
			printf("YES\n");
			int k=0;
			rep(i,n) 
				if ( vv[i].first == rr[k] ) {
					r.push_back(vv[i].second);
					k++;
					if ( sz(r) == 2 ) break;
				}

				rep(j,n) {
					if(r[0]==vv[j].second) {
						printf("%d %d ",vv[j].second+1 ,vv[j+1].second+1  );
						j++;
					}
					else if ( r[1] == vv[j].second) {
						printf("%d %d ",vv[j].second+1 ,vv[j+1].second+1  );
						j++;
					}
					else
						printf("%d ",vv[j].second+1);
				}
				printf("\n");
				rep(j,n) {
					if(r[0]==vv[j].second) {
						printf("%d %d ",vv[j].second+1 ,vv[j+1].second+1  );
						j++;
					}
					else if ( r[1] == vv[j].second) {
						printf("%d %d ",vv[j+1].second+1 ,vv[j].second+1  );
						j++;
					}
					else
						printf("%d ",vv[j].second+1);
				}
				printf("\n");
				rep(j,n) {
					if(r[0]==vv[j].second) {
						printf("%d %d ",vv[j+1].second+1 ,vv[j].second+1  );
						j++;
					}
					else if ( r[1] == vv[j].second) {
						printf("%d %d ",vv[j].second+1 ,vv[j+1].second+1  );
						j++;
					}
					else
						printf("%d ",vv[j].second+1);
				}
				printf("\n");


		}
		else 
			printf("NO\n");

		return 0 ;
}

