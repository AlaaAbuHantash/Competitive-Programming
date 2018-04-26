#define _CRT_SECURE_NO_WARNINGS
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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main()
{

    int n, m , a , b,x ;
    vector<int > v , vv ;
    cin >> n >> m >> a >> b ;
    for ( int i = 0 ; i < n ; i++ ){
            cin >>x ;
            v.push_back(x);

    }

    int c = 0 ;
    for ( int i = 0 ; i < m ; i++ ){
            cin >>x ;
        vv.push_back(x);
    }
    int mm = m-b;
  
    for(int i =0 ; i < n ; i++)
        if(vv[mm] > v[i])
            c++;

    if(c>=a)
        puts("YES");
    else
        puts("NO");
    return 0;
}