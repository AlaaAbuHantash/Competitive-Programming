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
int m;
const int N = 1e5;
int cnt[N + 10][3];
int c[3];
int main() {

    //freopen("b.txt", "rt", stdin);
    //freopen("myfile.txt", "w", stdout);
    cin >> s >> m;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cnt[i + 1][s[i] - 'x']++;

        cnt[i + 1][0] += c[0];
        cnt[i + 1][1] += c[1];
        cnt[i + 1][2] += c[2];
        c[s[i] - 'x']++;
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        a--;
        int aa = cnt[b][0] - cnt[a][0];
        int bb = cnt[b][1] - cnt[a][1];
        int cc = cnt[b][2] - cnt[a][2];
        //cout << aa << " " << bb << " & " << cc << endl;
        if ((abs(aa - bb) >= 2 || abs(bb - cc) >= 2 || abs(cc - aa) >= 2 || !aa || !bb || !cc) && (b - a > 2))
            puts("NO");
        else
            puts("YES");
    }

    return 0;
}
