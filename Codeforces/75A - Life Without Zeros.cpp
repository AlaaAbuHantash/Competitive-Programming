#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
int main()
{
	long long int a , b , c , x , y  ,sumx , m , sumy , c2 , z , sumz ; 

	cin >> a >> b ; 

	c = a + b ; 
	x=a ;
	sumx=0;sumy=0;sumz=0;
	while (x !=0 )
	{
		m = x %10 ; 
		if ( m != 0)
		{
			sumx = sumx + m ; 
			sumx = sumx *10;
		}
		x = x/10;
	}

	z = c ; 
	while (z !=0 )
	{
		m = z %10 ; 
		if ( m != 0)
		{
			sumz = sumz + m ; 
			sumz = sumz *10;
		}
		z = z/10;
	}

 //---------------------------------
	y = b ; 

	while (y !=0 )
	{
		m = y %10 ; 
		if ( m != 0)
		{
			sumy = sumy + m; 
			sumy = sumy *10;
		}
		y = y/10;
	}

	// reverce

	while (sumx != 0 )
	{
		m = sumx %10 ; 
		x = x + m ;
		x = x *10; 
		sumx = sumx / 10;
	}
	if ( x%10==0)
	x =x /10;

	//cout << x <<endl;

	while (sumy != 0 )
	{
		m = sumy %10 ; 
		y = y + m ;
		y = y *10; 
		sumy = sumy / 10;
	}
	if ( y%10==0)
	y=y/10;

	//cout << y <<endl;

	c2 = x + y  ;


	while (sumz != 0 )
	{
		m = sumz %10 ; 
		z = z + m ;
		z = z *10; 
		sumz = sumz / 10;
	}
	if ( z%10==0)
	z = z / 10;

	if ( c2 == z ) 
		cout << "YES" <<endl;
	else 
		cout << "NO"<<endl;
}