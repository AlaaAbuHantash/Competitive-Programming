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

int k;
map<int, bool> ma;
map<int, bool> ma2;
int n, m;
int tmp[55];
vector<int> v;
int c = 0;

void calc(int nub, int ind, int sum) {
    //cout << nub <<  " " << ind << " " << sum << endl;
    if (c >= m || ma[sum])
        return;
    if (nub == k) {
        if (!ma[sum] && sum && !ma2[sum]) {
            c++;
            printf("%d", nub);
            for (int i = 0; i < nub; i++)
                printf(" %d", tmp[i]);
            puts("");
        }
        ma[sum] = 1;
        ma2[sum] = 1;
        return;
    }
    if (ind >= n || nub > k || n - ind + nub < k)
        return;
    tmp[nub] = v[ind];
    if (!ma2[sum] && sum) {
        c++;
        printf("%d", nub);
        for (int i = 0; i < nub; i++)
            printf(" %d", tmp[i]);
        puts("");
        ma2[sum] = 1;
    }
    for (int i = ind; i < n; i++) {
        tmp[nub] = v[i];
        calc(nub + 1, i + 1, sum + v[i]);
    }

}
int main() {

    //freopen("b.txt", "rt", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    k = n;
    while (c < m && k>0) {
        calc(0, 0, 0);
        k--;
    }
    //cout << c << endl;
    return 0;
}