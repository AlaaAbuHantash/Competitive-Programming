
#include <iostream>
#include <vector> 
#include <iomanip>
#include <string>

using namespace std; 

int main()

{

	long long int T ,N ,sum=0 , i ,z ;
	cin >> T; 
	for(i=0 ; i <T ; i++)
	{
		sum=0;
		cin >>N;
		sum=( N * (3*N + 1) )/ 2;
		if (sum >= 1000007)
		{
		z= sum/1000007;
		sum = sum - z*1000007 ; 
		}
		cout<< sum << endl; 
		
	}




return 0 ;
}

