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
int main(){
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t ; 
	cin >> t ; 
	int n , k ; 
	double p ; 
	while(t-- ) { 
		cin >> n >> p >> k ; 
		double res =  1;
		for ( int i = 0 ; i < k-1 ; i++ ) 
			res*= 1-p;
		res*=p; 
		double r = res ;
		for ( int i = n ; i <= 5000 ; i+=n ) 
			res += pow(1-p,i) * r;

		printf("%.4lf\n",res);
	}	
	return 0;
}