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
    int n , k ,x; 
    cin >> n >> k; 
    vector<int > g;
    vector<pair < int , int> > v;
    long long res = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        
        if (x % 10 == 0){
            res += x / 10;
            g.push_back(x);
        }
        else{
            res += x / 10;
            v.push_back(mp(x % 10,x));
        }
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); i++){
        if (!k)
            break;
        int xx = 10-v[i].first;
        if (k >= xx){
            k -= xx;
            res++;
            g.push_back(v[i].second + xx);
        }
        else
            break;
    }
    sort(g.rbegin(), g.rend());
    for (int i = 0; i < g.size(); i++){
        int xx = 100 - g[i];
        if (k >= xx){
            res += xx / 10;
            k -= xx;
        }
        else{
            res += k / 10;
            break;
        }
    }
    cout << res << endl;
    return 0;
}