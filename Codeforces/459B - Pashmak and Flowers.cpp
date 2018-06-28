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
*   You got a dream, you gotta protect it.
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
int n , x;
long long int c; 
vector<int > a ;
map<int , int > m;
map<int , int > :: iterator it2;
int  main()
{   
  // freopen("test.in" , "rt" , stdin);
    scanf("%d",&n ) ; 
    pair<int , int > p;
    m.clear();
    rep(i,n) {
        scanf("%d",&x) ;
        a.pb(x);
        m[x]++;
    }
    sort(a.begin (), a.end());
    x = a[sz(a)-1] - a[0] ; 
    printf("%d ",x);
    c=0;
    if ( x != 0 ) {
        cout <<(long long) ( m[a[0]] * (long long)m[a[sz(a)-1]])  << "\n";
    }
    if ( x == 0 ) {
        c=0;
        for ( it2 = m.begin() ; it2 != m.end() ; it2++)  {
            if ( m[it2->first]  >= 2 ) {
                c+=((long long )((m[it2->first]-1) *(long long ) m[it2->first] ) /2 ) ; 
            }

        }
        cout << c << "\n";

    }
    return 0 ;
}