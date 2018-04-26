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
// possible ! 
int w, h;
bool f = 0; 
void fun(int a, int b, int aa, int bb, int aaa, int bbb){
    if (a + aa + aaa == w && b == bb && bb== bbb && b == h){
        printf("%d\n", h);
        for (int i = 0; i < a; i++){
            for (int j = 0; j < h; j++)
                printf("A");
            puts("");
        }
        for (int i = 0; i < aa; i++){
            for (int j = 0; j < h; j++)
                printf("B");
            puts("");
        }
        for (int i = 0; i < aaa; i++){
            for (int j = 0; j < h; j++)
                printf("C");
            puts("");
        }
        f = 1;
        return;
    }
    if (b == h && a + bb == w&& bb == bbb && aa + aaa == h){
        printf("%d\n", h);
        for (int i = 0; i < h; i++){
            for (int j = 0; j < h; j++){
                if (j < a)
                    printf("A");
                else if (i < aa)
                    printf("B");
                else
                    printf("C");
            }
            puts("");
        }

        f = 1;
        return ;
    }
    if (bb == h && aa + b == w && b == bbb && a + aaa == h){
        printf("%d\n", h);
        for (int i = 0; i < h; i++){
            for (int j = 0; j < h; j++){
                if (j < aa)
                    printf("B");
                else if (i < a)
                    printf("A");
                else
                    printf("C");
            }
            puts("");
        }

        f = 1;
        return ;
    }
    if (bbb == h && aaa + b == w && bb == b && a + aa == h){
        printf("%d\n", h);
        for (int i = 0; i < h; i++){
            for (int j = 0; j < h; j++){
                if (j < aaa)
                    printf("C");
                else if (i < aa)
                    printf("B");
                else
                    printf("A");
            }

            puts("");
        }

        f = 1;
        return ;
    }

}
int main() {
    //freopen("test.txt", "rt", stdin);
    int a, b, aa, bb, x, y; 
    cin >> a >> b >> aa >> bb >> x >> y;
    for (int i = 1; i <= 300 && !f; i++){
            w = i, h = i;
            if (!f)
                fun(a, b, aa, bb, x, y);
            if (!f)
                fun(a, b, aa, bb, y, x);
            if (!f)
                fun(a, b, bb, aa, x, y);
            if (!f)
                fun(a, b, bb, aa, y, x);
            if (!f)
                fun(b, a, aa, bb, x, y);
            if (!f)
                fun(b, a, aa, bb, y, x);
            if (!f)
                fun(b, a, bb, aa, x, y);
            if (!f)
                fun(b, a, bb, aa, y, x);
    }

    if (!f)
        puts("-1");
    return 0;
}