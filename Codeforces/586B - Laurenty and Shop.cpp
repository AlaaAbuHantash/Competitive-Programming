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

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n;
int a[3][55];
int b[55];
int main() {
    //freopen("a.txt" , "rt" , stdin);
    //freopen ("myfile.txt","w",stdout);
    cin >> n;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n -1; i++)
            cin >> a[j][i];
    }

    for ( int i = 0 ; i < n ; i++ )
        cin >> b[i];
    vector<int > res;
    int sum = 0 ;
    for ( int i = 0 ; i < n ; i++ ){
        sum = b[i];
        bool f = 0 ;
        for ( int j = 0 ; j < n-1; j++ ){
            if(i==j){
                f=1;
            }
            sum+=a[f][j];
        }
        res.push_back(sum);
        //cout << i << " " <<sum << endl;
    }
    sort(res.begin(),res.end());
    cout << res[0] + res[1] << endl;

    return 0;
}