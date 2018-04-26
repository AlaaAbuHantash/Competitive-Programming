#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip> 
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
int c[101][33];
int cc[101][33];
int  main(){
    //freopen("test.txt", "rt", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int n, m;
    cin >> n >> m;
    vector<string > v;
    for (int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            c[j][v[i][j] - 'a']++;
            cc[i][v[i][j] - 'a']++;
        }
    }

    string tmp = "";
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (c[j][v[i][j] - 'a'] >= 2 || cc[i][v[i][j] - 'a'] >= 2)
                continue;
            else
                tmp += v[i][j];
    }
    cout << tmp << endl;
    return 0;
}