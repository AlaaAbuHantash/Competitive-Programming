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

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
    //freopen("a.txt" , "rt" , stdin);
    //freopen ("myfile.txt","w",stdout);

    int n, x;
    cin >> n;
    int a = 0, b = n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (v[i] == 1) {
            a = i;
            break;
        }

    for (int i = n - 1; i >= 0; i--)
        if (v[i] == 1) {
            b = i;
            break;
        }
    int res = 0;
    bool f = 0,g=0;
    for (int i = a; i <= b; i++) {
        if (v[i] == 1) {
            res++;
            if (f)
                res++;
            f = 0;
            g = 0;
        } else if (v[i] == 0) {
            if (f||g){
                f = 0;
                g = 1;
            }
            else
                f = 1;
        }
    }
    cout << res << endl;
    return 0;
}