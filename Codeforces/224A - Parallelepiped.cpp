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
#include<math.h>
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {

    //freopen("input", "rt", stdin);
    //freopen ("myfile.txt","w",stdout);
    double a , b , c ;
    cin >> a >> b >>c ;
    int x = sqrt((a*b) / c ) ;
    int y = a / x ;
    int z = b / x ;
    int res = x * 4 + y *4 + z * 4 ;
    cout << res <<"\n";

    return 0;
}
