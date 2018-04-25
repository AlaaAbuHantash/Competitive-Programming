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
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, k;
vector<string> v;
bool ff = 0;
int vis[105][4][4];
void calc(int ind, int col, int f) {

    if (ind >= n || ff) {
        ff = 1;
        return;
    }
    if (v[col][ind] != '.')
        return;
    if (vis[ind][col][f])
        return;
    vis[ind][col][f] = 1;
    if (!f) {
        if (ind + 1 < n && v[col][ind + 1] != '.')
            return;
        else if (ind + 1 < n) {
            if (col == 0)
                calc(ind + 1, col + 1, 1);
            else if (col == 1) {
                calc(ind + 1, col + 1, 1);
                calc(ind + 1, col - 1, 1);

            } else if (col == 2)
                calc(ind + 1, col - 1, 1);
        }
        calc(ind + 1, col, 1);

    } else {
        if (ind + 1 < n && v[col][ind + 1] != '.')
            return;
        if (ind + 2 < n && v[col][ind + 2] != '.')
            return;
        calc(ind + 2, col, 0);
    }

}
int main() {
    //freopen("a.txt", "rt", stdin);
    //freopen ("myfile.txt","w",stdout);
    int t;
    cin >> t;
    string s;
    while (t--) {
        ff = 0;
        memset(vis, 0, sizeof(vis));
        cin >> n >> k;
        v.clear();
        for (int i = 0; i < 3; i++) {
            cin >> s;
            v.push_back(s);
        }

        int st = 0;
        for (int i = 0; i < 3; i++)
            if (v[i][0] == 's') {
                st = i;
                v[i][0] = '.';
            }
        calc(0, st, 0);
        if (ff)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}