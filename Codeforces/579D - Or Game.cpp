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
#define mp make_pair
int cnt[33];
int  main(){
    //freopen("test.txt", "rt", stdin);
    long long  n, k, x, a;
    cin >> n >> k >> x;
    long long r = 0, res = 0;
    vector<pair <long long, int >  > v;
    for (int i = 0; i < n; i++){
        cin >> a;
        int c = 0;
        long long tmp = a;
        while (tmp != 0){
            if (tmp % 2 == 1)
                cnt[c]++;
            c++;
            tmp /= 2;
        }

        v.push_back(mp(a, c));
        r = r | a;

    }
    sort(v.rbegin(), v.rend());
    int mx = v[0].second;
    long long rr = 1; 
    for (int i = 0; i < k; i++)
        rr = rr*x;
    for (int i = 0; i < v.size(); i++)
    {
        //if (v[i].second != mx)
            //break;
        long long tmp = v[i].first;
        long long msk = (1 << 30) - 1;
        int c = 0;
        while (tmp != 0){
            if (tmp % 2 == 1 && cnt[c] == 1)
                msk = msk&~(1 << c);
            c++;
            tmp /= 2;
        }
        tmp = r&msk; 
        res = max(res, (tmp | (v[i].first*rr)));
    }
    cout << res << endl;

    return 0;
}