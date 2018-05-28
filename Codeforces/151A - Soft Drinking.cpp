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
#include <math.h>
using namespace std;
int main()
{

	int i, n, k, l, c, d, p, nl, np ,r[3] ,sum ;
	cin >>  n>> k>> l>> c>> d>> p>> nl>> np;
	r[0] = (l*k)/nl;
	r[1] = d*c;
	r[2]= p / np ; 

	sum = r[0] ;
	for (i = 0 ; i < 3 ; i++)
		if (r[i]<sum)
			sum =r[i];
	cout << sum/n <<endl;
}
