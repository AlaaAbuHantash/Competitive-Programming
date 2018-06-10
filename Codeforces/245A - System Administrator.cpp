#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{
	int n , i  ,suma = 0 , sumb = 0 , ra = 0 , rb = 0 ; 
	cin >> n ; 
	vector <int> t (n);
	vector <int> x (n);
	vector <int> y (n);

	for (i=0 ; i<n ; i++)
		{
			cin >> t[i] >> x[i] >> y[i] ;
			if(t[i] == 1 ) 
			{
					suma = suma + x[i] + y[i];
					ra = ra + x[i];
		     }
			else
			{
				sumb = sumb + x[i] + y[i];
				rb = rb + x[i];
			}

	    }

	if(ra >= (suma/2)) cout << "LIVE"<<endl;
	else cout << "DEAD" <<endl;
	
	if(rb >= (sumb/2)) cout << "LIVE"<<endl;
	else cout << "DEAD" <<endl;




}
