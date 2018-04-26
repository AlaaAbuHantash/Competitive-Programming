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
int vis[11];
bool chk(string ala) {
    int mod = 0;
    for (int i = 0; i < ala.length(); i++)
        mod = ((mod * 10) + (ala[i] - '0')) % 7;
    if (mod == 0)
        return 1;
    return 0;
}
int main() {
    //freopen("b.txt", "rt", stdin);
    string s = "1689";
    string ss, nub = "";
    cin >> ss;
    for (int i = 0; i < ss.length(); i++) {
        if ((ss[i] == '6' || ss[i] == '1' || ss[i] == '9' || ss[i] == '8')
                && !vis[ss[i] - '0'])
            vis[ss[i] - '0'] = 1;
        else
            nub += ss[i];
    }
    do {
        string r = s + nub;
        if (chk(r)&&r[0] !='0') {
            cout << r << endl;
            return 0;
        }
        r = nub + s;
        if (chk(r)&&r[0] !='0') {
            cout << r << endl;
            return 0;
        }
        for (int i = 1; i < 4; i++) {
            string tmp1 = s.substr(0, i);
            string tmp2 = s.substr(i);
            r = tmp1 + nub + tmp2;
            if (chk(r)&&r[0] !='0') {
                cout << r << endl;
                return 0;
            }
        }
    } while (next_permutation(s.begin(), s.end()));
    puts("0");

}