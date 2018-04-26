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
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s[] = { "Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy",
        "Hexadecimal" };
int c[8][8];
map<string, int> m;
int fun(string &g, int st, int end) {
    int cnt = 0;
    for (int i = st; i < end; i++)
        for (int j = st; j < end; j++)
            if (c[g[i] - '0'][g[j] - '0'])
                cnt++;
    return cnt;
}
int main() {
    //freopen("a.txt", "rt", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 7; i++)
        m[s[i]] = i;
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b >> b;
        c[m[a]][m[b]] = 1;
    }

    int x, y, z;
    cin >> x >> y >> z;
    string ss = "0123456";
    int res = -1, ress = -1;
    do {

        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 6 - i; j++) {

                int a1 = max(x / i, max(y / j, z / (7 - (i + j))));
                int b1 = min(x / i, min(y / j, z / (7 - (i + j))));
                int xx = a1 - b1 ;
                //cout << i << " " << j << " " << (7 - (i + j)) << " " << xx
                    //          << endl;
                if (res == -1 || res >= xx) {
                    int yy = fun(ss, 0, i)
                            + fun(ss, i, j + i)+ fun(ss, j + i, 7);
                    //cout << yy << endl;
                    if (res == -1 || res > xx)
                        res = xx, ress = yy;
                    else
                        ress = max(ress, yy);

                }
            }
        }
    } while (next_permutation(ss.begin(), ss.end()));
    printf("%d %d\n", res, ress);
    return 0;
}