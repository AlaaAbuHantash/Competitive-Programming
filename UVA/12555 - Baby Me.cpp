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
double a[2];
int main(){
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int t ,tt=1; 
	cin >> t ; 	
	while(t-- ){
		 double res = 0 ; 
		a[0] = 0.0 , a[1] = 0.0 ; 
		string s, tmp ;
		cin >> s ; 
	
		stringstream A(s) ; 
	 
		A>>a[0];
		A>> tmp;
		for (int i = 0 ; i < tmp.size() ; i++ ) {
			if(tmp[i] >='0' && tmp[i] <='9'){
				a[1] = tmp[i] -'0';
			}
		}
		res = a[0] *0.5 + a[1] * 0.05; 
		printf("Case %d: ",tt++);
		cout << res << "\n"; 
	}
	return 0;
}