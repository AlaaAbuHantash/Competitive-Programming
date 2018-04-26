#include<stdio.h>
#include <iostream>
#include <vector> 
#include <iomanip>
#include <string>

using namespace std; 

int main()

{

	 int T ,N ,sum=0 , i ,z  ; 
	scanf("%d",&T);
	for(i=0 ; i <T ; i++)
	{
		sum=0;
		scanf("%d",&N);
		for(z=1; z*z<N; z++)
		         if (N%z==0)
					 sum = sum + (z + N /z);
		   

		  if ( z*z == N ) 
				sum =sum + z; 

		  sum = sum - N ; 

		  if (N==1)
			sum = 0 ;			  

		printf("%d\n",sum);
		
	}




return 0 ;
}

