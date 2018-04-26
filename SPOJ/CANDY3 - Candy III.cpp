
#include <iostream>
#include <vector> 
#include <iomanip>
#include <string>

using namespace std; 

int main()

{

	long long int T ,N ,sum;
	cin >> T; 
	for( int i = 0 ; i <T ; i++ ) 
	{
		sum = 0 ; 
    cin >> N ; 
	vector <long long int> Nub (N) ; 
	for ( int z = 0 ; z < N ; z++ ) 
		{
			cin >> Nub[z]; 
			sum = (sum+ Nub[z]) %N;
		
	    }

	if ( sum  == 0 ) 
	     cout <<"YES"<<endl; 
	else 
		cout << "NO" <<endl; 
	}




return 0 ;
}

