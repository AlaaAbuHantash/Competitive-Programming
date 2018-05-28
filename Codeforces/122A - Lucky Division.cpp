#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
int main()
{

	int n ,x , z;
	int a[]={4 , 44 , 444 ,  7 , 77 , 777 ,  47 , 74 , 447, 474 , 477 , 744 , 747 , 774 };
	cin >> n ; 
	x=n ; 
	bool f = true , f2 = false ;
	while ( x != 0 ) 
	{
		z = x%10 ; 
		if ( z != 4 || z != 7  ) 
		{
			f = false; 
			break;
		}
		z = z /10;
	}

	
	if ( !f ) 
	{
		for ( int i = 0 ; i < 14 ; i++ ) 
			if ( n%a[i] == 0 ) 
			{
				f2=true; 
				break;
			}
	}


	if ( f || f2 ) 
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	return 0;
}
