#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k , n , i , c = 0 ; 

	cin>> n >> k ; 
	vector <int>a (n+1); 
	for (i = 1 ; i <= n ; i++) 
		cin >> a[i];


	for (i = 1 ; i <= n ; i++) 
	     if(a[i] >= a[k] && a[i] != 0 )
			 c++;

	cout << c <<endl; 




  return 0;
}
