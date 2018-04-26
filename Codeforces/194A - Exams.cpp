#include <cstdio>
#include <iostream>
#include<vector>
#include<cctype>
#include <algorithm>

using namespace std; 

int main()
{
int n , k ;

	cin >>n >> k ; 
	if (k-n*2 == 0)
		cout << k/2 <<endl; 
	else if (n-(k-n*2) > 0 )
	{
	cout << n-(k-n*2) << endl; 

	}
	else 
		cout << "0" << endl; 



return 0;
}

