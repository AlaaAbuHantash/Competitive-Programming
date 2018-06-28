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
int n,a,b,m;
int dp[1005] ; 
int calc (  int nn) {
    //cout << nn << endl;
    if ( nn >= n ) return 0 ;
   

    if (dp[nn]!=-1)return dp[nn];
    int r1 = calc ( nn + m ) + b ; 
    int r2 = calc ( nn + 1 ) +a; 
    return dp[nn]=min ( r1, r2) ; 
}
int  main()
{
    //freopen("test.in" , "rt" , stdin);
    mem(dp,-1);
    scanf("%d%d%d%d",&n,&m,&a,&b) ; 

    cout << calc ( 0 )  <<endl;
    return 0 ;
}