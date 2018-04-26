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
string s;
char a[5001][5001];
int v[5001][5001];
int main() {
    //freopen("test.txt", "rt", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    //vector<vector<int > > v(m);
    for (int i = 0; i < n; i++)
        for (int j = m - 1, c = 0; j >= 0; j--) {
            if (a[i][j] == '1')
                c++;
            else
                c = 0;
            v[j][i] = c;
        }

    for (int i = 0; i < m; i++) {
        sort(v[i], v[i] + n);
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        int val = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (val == -1 || v[i][j] < val)
                val = v[i][j];
            int x = val * (n - j);
            //cout << " " << val << " " << j << endl;
            res = max(x, res);
        }
    }
    printf("%d\n", res);
    return 0;
}