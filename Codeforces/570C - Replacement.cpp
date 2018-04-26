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
int n, m;
int main() {
    //freopen("b.txt", "rt", stdin);
    cin >> n >> m >> s;
    int c = 0, pos;
    char ch;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1] && s[i] == '.')
            c++;

    for (int i = 0; i < m; i++) {
        cin >> pos >> ch;
        pos--;
        if ((s[pos] >= 'a' && s[pos] <= 'z' && ch >= 'a' && ch <= 'z')
                || s[pos] == ch) {
            cout << c << endl;
            continue;
        }
        if (ch == '.') {
            if (pos - 1 >= 0 && s[pos - 1] == '.')
                c++;
            if (pos + 1 < n && s[pos + 1] == '.')
                c++;
        } else {
            if (pos - 1 >= 0 && s[pos - 1] == '.')
                c--;
            if (pos + 1 < n && s[pos + 1] == '.')
                c--;
        }

        cout << c << endl;
        s[pos] = ch;
    }
}