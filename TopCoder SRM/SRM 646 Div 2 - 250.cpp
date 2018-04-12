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

/*
*	You got a dream, you gotta protect it.
*/ 
using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;  
class TheConsecutiveIntegersDivTwo {
public : 
	int find(vector <int> numbers, int k) {
		int r =-1 ; 
		if ( k == 1 ) r = 0 ; 
		else {
			sort(numbers.begin() , numbers.end()) ; 
			for ( int i = 0 ; i < numbers.size() -1 ; i++) {
				if ( r == -1 ) 
					r = abs ( numbers [i+1] - numbers[i]  -1 ) ; 
				else 
					r = min ( r , abs ( numbers [i+1] - numbers[i] -1  ) )  ; 
			}
		}
		return r ; 
	}
};
int  main()
{
	//freopen("input.in" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);

	return 0 ;
}