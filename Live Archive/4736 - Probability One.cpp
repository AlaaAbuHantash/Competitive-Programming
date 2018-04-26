#include<stdio.h>
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include<iomanip>

using namespace std; 

 
int main()
{
	string s;
	int n , n1 , n2 ,n3 , n4 , i =1 ; 
	cin >> n ; 
	while (n!=0)
	{
		n1 = 3* n ; 
		if ( n% 2== 0 ) 
		{n2 = n1 /2;
		s = "even ";}
		else
		{n2 = (n1 + 1)/2; s = "odd ";}
			

		n3 = 3*n2;
		n4= n3/9 ;

			if ( n1% 2 == 0 ) 
			n=n4*2 ; 
		      else
				   n = 2*n4 + 1;

		cout << i <<". "<<s <<n4 <<endl;
		i++;
	cin >> n;
	}


return 0;
}

