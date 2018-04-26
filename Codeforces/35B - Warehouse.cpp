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
map < string, pair < int, int > > pos;
int a[33][33];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, q,x,y; 


    scanf("%d%d%d", &n, &m, &q);
    string s;
    for (int k = 0; k < q; k++){
        cin >> s; 
        if (s == "-1"){
            cin >> s;
            if (pos[s].first == 0)
                puts("-1 -1");
            else 
                printf("%d %d\n", pos[s].first, pos[s].second);
            
            a[pos[s].first][pos[s].second] = 0;
            pos[s].first = 0;
            pos[s].second = 0;
        }
        else {
            bool f = 0;
            cin >> x >> y >> s;
            if (a[x][y] == 0)
                pos[s].first = x, pos[s].second = y, a[x][y] = -1;
            else {
                for (int i = y + 1; i <= m&&!f; i++)
                    if (a[x][i] == 0) 
                        pos[s].first = x, pos[s].second = i, a[x][i] = -1,f=1;
                if (!f){
                    for (int i = x + 1; i <= n&&!f; i++)
                        for (int j = 1; j <= m&&!f; j++)
                            if (a[i][j] == 0)
                                pos[s].first = i, pos[s].second = j, a[i][j] = -1, f = 1;       
                }
            }
        }
    }
    return 0;
}