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
using namespace std; 
int n , a , b ;
#define pi 2 * acos(0);
int main () {
    //freopen("test.in" , "rt" , stdin);
    scanf("%d",&n ) ; 
    int g = 1 ;
    while(n--) {
        cin >> a >> b ; 
        double c = 2.0 * a * (  22.0 / 7.0 ); 
        
        printf("Case %d: " , g++);
        cout << int (  b/c )   << endl;
    }
    return 0 ; 
}