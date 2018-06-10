#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
#include<iomanip>
using namespace std;
int main()
{

	int n , i , l,r,  lo =0 , lc = 0 ,ro = 0 , rc = 0 ;
	cin >> n ; 
	for ( i= 0 ; i < n ; i++)
	{
		cin >> l >> r ; 
		if (l)lo++;
		else if (!l) lc++;
		if (r) ro++;
		else if (!r) rc++ ;
	}

	if (lc>lo) l=lo;
	else l = lc ; 
	if (rc>ro) r = ro ; 
	else r = rc ; 

	r = r+ l ; 
	cout << r << endl;
}