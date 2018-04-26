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
int c[111];
int  main()
{
    //freopen("test.txt", "rt", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int res = 0;
    while (s != "1"){
        int len = s.length() - 1;
        while (len >= 1 && s[len] == '0'){
            s.erase(len, 1);
            res++, len--;
        }
        if (s[len] == '1' && len!=0){
            res+=2;
            s.erase(len, 1);
            len--;
            while (len >= 1 && s[len] == '1'){
                s.erase(len, 1);
                res++;
                len--;
            }

            if (len >= 1 && s[len] == '0')
                s[len] = '1';

            if (len == 0 && s[len] == '1')
                res++;

        }
    }
    printf("%d\n", res);
    return 0;

    
}