#include <cstdio>
#include <iostream>
#include<string>
#include<vector>
#include<cctype>
#include <algorithm>

using namespace std; 

 
int main()
{
int T , N  , i , x = 0 , y = 0, w;  
string s1 , s2 , s , sum1= "" , sum2= "" , sum3= "" ; 
cin >> T;
while (T--)
{
sum2 = "" ; 
sum1 = "" ; 
sum3 = "" ; 

	x = 0;  y = 0; w=0;
	cin >>N ;
	for ( i = 0; i < N ; i++) 
	{
		cin >> s ;

		if (s[0]=='#' && (x != 1)) 
		{ 
			if(i==0)
				sum1 = s ; 
			else 
				sum1 = sum1 +" "+s ; 
			y=1;
		}
		else if (x == 1)
		{
		   sum3 = sum3 + s + " "   ;
		}
		else 
		{ 
	       sum2 = sum2 + s  ;
		   x = 1;
		   w = 1;
	}

	}
	if(w==1 && y == 1 )
     cout << sum3 +sum2+ " "+ sum1<<endl;
	else 
     cout << sum3 +sum2+sum1<<endl;
}

return 0;
}

