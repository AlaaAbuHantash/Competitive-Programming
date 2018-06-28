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
int n;
long long sum ,k;
string s ;
long long  a[30];
vector<long long > b ;
int  main()
{   
    //freopen("test.in" , "rt" , stdin);
    scanf("%d%I64d",&n,&k ) ; 
    cin >> s  ; 
    mem(a,0);
    for (int i=0;i<sz(s);i++)
        a[s[i]-'A']++;
    for (int i=0;i<26;i++) {
        if ( a[i]!=0)
            b.pb(a[i]);
    }
    sum=0;
    sort(b.rbegin(),b.rend());
    for (int i=0;i<sz(b) ;i++) {
        if ( k==0)
            break;
        if (b[i] <= k ) {
            sum = sum + ((b[i]) * (b[i]) ) ;
            k-=b[i];
        }
        else if ( b[i] > k ) { 
            sum = sum + (long long (k )* long long (k)) ;
            k=0;
        }
    }
    if (k!=0 ) 
        sum = sum +k ;
    printf("%I64d\n",sum);
    return 0 ;
}