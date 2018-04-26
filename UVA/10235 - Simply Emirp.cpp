#include<stdio.h>
#include <iostream>
using namespace std; 

int z =0 ;
int IsPrime(long p)
{
		for(z=2; z<=p/2; z++)
		  if (p%z==0)
			  return 0;


			  return 1;
}

int main()

{
long  N ,r , x ,nub ,y  ,N2 ,r2;
while(cin>>N)
{
			if(N<=1)
			{
			cout <<N<< " is prime."<<endl;
			continue ; 
			} 

	
	r=0;

	N2 = IsPrime(N) ;
	 if (N2 == 0 ) 
		   {
			   cout <<N<< " is not prime."<<endl;
	           continue ; 
	        }

	 x=N;
	while (x != 0 )
	{
		
		y=x%10;
		r = (r*10) + y ;
		x=x/10;
	
	} 
	r2 =IsPrime(r);
	
		  if ( N2 == 1 && r2==1 && N>10 && N!=r)
            cout <<N<< " is emirp."<<endl;
		  else if (N2==1)
			  cout<<N << " is prime."<<endl;
		  
		  


}

return 0 ;
}

