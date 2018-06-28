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
using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;  
int  main()
{
    //freopen("test.in" , "rt" , stdin);
    int a,b,c,d, e; 
    int sum=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e) ; 
    sum=a+b+c+d+e;
    bool f=1;
    if( a== b && b==c && c == d && d == e && a==0 ) 
        f=0;
    if ( sum % 5 == 0 && f) {
        int x = sum / 5 ; 
/*      if ( a == x || b == x || c == x || d == x || e ==x ) 
            printf("%d\n",-1); 
        else*/ 
            printf("%d\n",sum/5 ) ; 
    }
    else 
        printf("%d\n",-1); 

    return 0 ;
}