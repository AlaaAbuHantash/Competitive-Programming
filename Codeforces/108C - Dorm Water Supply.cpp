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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int cc[1001];
int vis[1001];
vector<vector<pair < int , int > > > v;
int r,ed;
void calc(int nod, int xx){

    if (v[nod].size() == 0){
        r = xx;
        ed = nod; 
        return;
    }
    calc(v[nod][0].first, min(xx, v[nod][0].second));
}
int main() {
    //freopen("test.txt", "rt", stdin);
    //freopen("output.txt", "w", stdout);

    int n, p, a, b, c; 
    cin >> n >> p; 
    
    v.clear();
    v.resize(n);
    for (int i = 0; i < p; i++){
        cin >> a >> b >> c;
        cc[b-1]++;
        vis[a-1] = 1;
        v[a - 1].push_back(mp(b - 1, c));
    }
    vector<int > st; 
    for (int i = 0; i < n; i++)
        if (cc[i] == 0&& vis[i])
            st.push_back(i);
        
    

    vector<pair < int ,pair<int , int > > > res;
    for (int i = 0; i < st.size(); i++){
        r = 0;
        calc(st[i],1000000);
        res.push_back(mp(r, mp(st[i], ed)));
    }
    cout << res.size() << endl; 
    for (int i = 0; i < res.size(); i++)
        printf("%d %d %d\n", res[i].second.first+1, res[i].second.second + 1, res[i].first);
    return 0;
}