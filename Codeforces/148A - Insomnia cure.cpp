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
#include <string.h>
#include <math.h>
#include <cmath>
using namespace std;

int main () 
{
	int k , l , m , n , d ,s , i ;
	cin >>k>>l>>m >>n>>d;
	s=0;
	for ( i = 1 ; i <= d ; i++ )
	{
		if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
			s++;
	}

cout << s <<endl;
	return 0 ;
}