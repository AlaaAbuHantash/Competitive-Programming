/**			
***** Judge
******* Yourself 
********* Only   
*/
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
int main()
{	
	//freopen("a.txt", "rt", stdin);
	int t ; 
	cin >> t ; 
	while(t-- ) {
		string s ; 
		cin >> s ; 
		string a = s ; 
		sort(a.begin(),a.end()) ; 
		s+=s;
		string res="" ; 
		int r = -1 ; 
		int n = a.size();
		for( int i = 0 ; i < n; i++ ) {
			if(s[i] == a[0] ) {
				string tmp = s.substr(i,n);
				if(r == -1 || tmp < res ) {
					res = tmp ; 
					r = i +1 ; 
				}
			}
		}
		printf("%d\n",r);

	}
	return 0;
}