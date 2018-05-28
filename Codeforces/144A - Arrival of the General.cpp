#include <cstdio>
#include<stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include<sstream>
#include <map> 
#include <iomanip>
using namespace std;
int main()
{
	 int n  , i , max , min , a , b; 
	 cin >> n ; 
	 vector <int> s (n+1);

	 for (i = 1 ; i <= n ; i++) 
	 {
		 cin >> s[i];
		  
	 }
	 min = s[1];
	 max = s[1];
	 a=1 ; b=1;
	 for (i = 1 ; i <= n ; i++) 
	 {
		 if (s[i]> max)
		 {
			 max = s[i];
			 a= i ;
		 }
	 
	 
		 if (s[i]<=min)
		 {
			 min = s[i];
			 b=i;
		 }
	 
	 }

	  int r ;
	 if (a>b) 
		 r= n-b + a -2 ;
	 else 
		 r= n-b + a-1 ;

	 cout << r <<endl;


}
