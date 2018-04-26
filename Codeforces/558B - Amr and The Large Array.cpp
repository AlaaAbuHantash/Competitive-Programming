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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a[1000005];
int arr[1000005];
int lst[1000005];

int vis[1000005];
int main() {
   // freopen("A.txt", "rt", stdin);
    //freopen ("myfile.txt","w",stdout);
    int n, x, m = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        m = max(m, a[x]);
        v.push_back(x);
    }
    //cout << m << endl;
    int st = 0, d = -1, res = 10000000;
    for (int i = 0; i < n; i++) {
        if (!vis[v[i]])
            lst[v[i]] = i;
        vis[v[i]] = 1;
        arr[v[i]]++;
        if (arr[v[i]] == m) {
            if (i - lst[v[i]] + 1 < res) {
                st = lst[v[i]];
                d = i;
                res = i - lst[v[i]] + 1;
            }

        } else if (arr[v[i]] > m) {
            while (arr[v[i]] > m) {
                lst[v[i]]++;
                if (v[lst[v[i]]] == v[i])
                    arr[v[i]]--;
            }

            if (i - lst[v[i]] + 1 < res) {
                st = lst[v[i]];
                d = i;
                res = i - lst[v[i]] + 1;
            }
        }
    }
    cout << st + 1 << " " << d + 1 << endl;
    return 0;
}
