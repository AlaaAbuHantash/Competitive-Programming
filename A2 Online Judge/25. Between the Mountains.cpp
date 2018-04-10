#include <cmath>
#include <iostream>

using namespace std; 

 
int main()
{
	int t , A , B , i , j , result=1000000 , z; 
	int a[1005], b[1005];
	cin >> t ;
	while (t--)
	{
		result=1000000;
		cin >> A ;
		for ( i = 0 ; i< A ; i++)
		       cin >> a[i]; 

		cin >> B ;
		for ( i = 0 ; i< B ; i++)
		{	
			cin >> b[i];
			for (j = 0 ; j < A ; j++)
			{
				z = b[i] -a[j] ; 
				if ( z < 0 ) 
					z = z * -1 ; 

				if (z < result)
					 result = z ;
			}
		}


		cout << result <<endl;
	
	}

return 0;
}


