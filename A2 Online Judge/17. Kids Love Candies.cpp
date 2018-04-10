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
#include <stdio.h>
using namespace std;
int main()
{
	
	//freopen("test.in" , "rt" , stdin);
	int t  ,K,N , i ,sum;
	int n[100];
	cin >> t ; 
	while ( t-- ) 
	{
		cin >> N >> K ;
		sum = 0 ;
	for(i= 0 ; i<N ; i++)
		{
			cin >> n[i];
			sum = sum  + (n[i]/K);
	     }

	cout << sum << endl; 

}

	return 0;
}