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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
double ma[111];
int main() {
    //freopen("input", "rt", stdin);
    //freopen ("myfile.txt","w",stdout);
    int a=0 , n,res  ;
    cin >> n ;
    vector <int> v (n);
    for ( int i = 0 ; i < n ; i++){
        cin >>v[i];
        a+=v[i];
    }
    for ( int i = 0 ; i < n ; i++)
        if ((a-v[i]) % 2 == 0 ) res ++;
    cout << res <<"\n";
    return 0;
}
