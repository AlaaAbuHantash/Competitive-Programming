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
	string s ; 
	while(cin >> s ) {
		int n ; 
		cin >> n ; 
		stringstream A(s) ; 
		vector<long long > v ; 
		vector<char> c; 
		int x; 
		char ch ; 
		A>>x ; 
		v.push_back(x) ; 
		while(A>>ch){
			c.push_back(ch);
			A>>x;
			v.push_back(x);
		}
		bool f = 0 , ff = 0 ; 
		long long res = v[0] ; 
		for ( int i = 1 ; i < v.size() ; i++ ) {
			if(c[i-1] == '+' ) 
				res+= v[i] ; 
			else 
				res*= v[i];
		}

		if( res == n ) 
			f = 1 ; 

		for ( int i = 0 ; i < v.size()-1 ;i++) {
			if(c[i] == '*' ) {
				v[i+1]*=v[i] ; 
				v[i] = 0 ; 
			}
		}
		res = 0 ; 
		for ( int i = 0 ; i < v.size() ; i++ ) 
			res+=v[i] ; 
		if( res == n ) 
			ff = 1 ; 


		if(ff && f ) 
			puts("U");
		else if(f)
			puts("L");
		else if(ff)
			puts("M");
		else 
			puts("I");
		
	}	
	return 0;
}