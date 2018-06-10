#include <cstdio>
#include<stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <map> 
#include <cmath>
using namespace std;

int main () 
{
	//http://codeforces.com/problemset/problem/276/A
	long long int n , k  , i , st=0 , ft=0 ,s = 0 , z=-1000000000;; 
	cin>>n >> k; 
	vector <int> f(n) ; 
	vector <int> t(n) ;

	for (i=0 ;i<n ; i++)
	{
		cin >> f[i]>> t[i] ; 
		st=st+t[i] ; 
		ft = ft + f[i];
		if (k>t[i])
			s=f[i];
		else
			s = f[i]-t[i]+k;

		z = max(z,s);

	};

	cout <<z<<endl;
	return 0 ;
}