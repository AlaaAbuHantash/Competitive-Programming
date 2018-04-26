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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;

int main() {
    //freopen("test.txt", "rt", stdin);

    int n, m; 
    scanf("%d%d", &n, &m);
    vector<pair<int, int >  >v; 
    long long res = 0; 
    int a, b; 
    for (int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        v.push_back(mp(b, a));
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < m; i++){
        if (v[i].second <= n){
            n -= v[i].second;
            res += (v[i].second*v[i].first);
        }
        else{
            res += n*v[i].first;
            break;
        }
    }
    cout << res << endl;
    return 0;
}