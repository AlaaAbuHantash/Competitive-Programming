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

int main() {
    //freopen("A.txt", "rt", stdin);
    //freopen ("myfile.txt","w",stdout);
    int n, x, a;
    cin >> n;
    vector<pair<int, int> > v, v2;
    for (int i = 0; i < n; i++) {
        cin >> x >> a;
        if (x < 0) {
            v.push_back(mp(x, a));
        } else
            v2.push_back(mp(x, a));
    }

    sort(v.rbegin(), v.rend());
    sort(v2.begin(), v2.end());
    int i = 0;
    long long sum = 0;
    for (; i < v.size() && i < v2.size(); i++) {

        sum += v[i].second + v2[i].second;
    }
    if (i < v2.size())
        sum += v2[i].second;
    if (i < v.size())
        sum += v[i].second;
    cout << sum << endl;
    return 0;
}
