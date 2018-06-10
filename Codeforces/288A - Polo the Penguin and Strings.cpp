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
/*YOU got a DREAM, YOU gotta protect it. */

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int  main()
{
    //freopen("input" , "rt" , stdin);
    //freopen ("myfile.txt","w",stdout);
    int a,b ;
    cin >> a >> b ;
    if (a< b ||(b == 1 && a > 1))
        puts("-1");
    else {
        int z = a - b + 1 ;
        if(b>1)z++;
        string s = "";
        for ( int i = 0 ; i < z ; i++)
            if ( i%2 ==0) s+="a";
            else s+="b";
        for (int j='c', i = 2;j<='z' &&i<b;j++,i++)
            s+=j;
        cout << s<<"\n";
    }

    return 0 ;
}
