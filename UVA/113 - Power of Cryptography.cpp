/**			
***** Judge
******* Yourself 
********* Only   
*/
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
#include<cmath>
using namespace std;
#define mp make_pair
#define eps 1e-6
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("out.txt", "w", stdout);

    double a , b ; 
    while ( cin >> a >> b ) {
        double res = powl(b,1.0/a);
       cout << (int)round(res)<< endl; 
    }
    
}





