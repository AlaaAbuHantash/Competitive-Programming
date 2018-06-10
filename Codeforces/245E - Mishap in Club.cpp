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
#include<math.h>
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	string s ;
	cin >> s ;
	int  a = 0 , b = 0 ,c = 0   ;
	for ( int i = 0 ; i < s.length() ; i++ )
		if ( s[i] == '-' ){
			if (a == 0 ){
				c++ ;
				b++;
			}
			else {
				b++;
				a--;
			}
		}
		else if(s[i] == '+' ){
			if ( b == 0 ){
				c++;
				a++;
			}
			else{
				a++;
				b--;
			}

		}
	printf("%d\n" , c );
	return 0;
}


