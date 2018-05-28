#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int gcd (int n , int k )
{
	int i ; 

/*if( k == 0 )
   return n ; 
else if( n == 0 )
   return k ; 
*/
for (i = n ; i > 0 ; i--)
		{// cout << i <<endl ;
			if (k%i == 0 && n%i==0 ) 
	    	return i; }


}

int main()
{
	int a , b , k , count1= 0 ,count2= 0 , r= 1;
	bool flag = true ; 
  //  cout << gcd (5,6)<<endl ;
	cin >> a >> b >> k ; 


	while (k)
	{
		if ( flag  )
		{
			r = gcd (a,k) ; 
			k = k - r;
            flag = false;
			count1++;
		 //  if (a >k)
		//	{cout <<0 << endl;break;} 

		}
		else 
		{
			r= gcd (b,k) ; 
			k = k - r;
            flag = true;
			count2++;
			//if (b > k)
			//{cout <<1 << endl;break;} 


		}
			//cout << r <<"  "<<k << endl;

	}


	
	if(count1 > count2)
		cout << 0 << endl; 
	else 
		cout <<1 << endl; 

  return 0;
}
