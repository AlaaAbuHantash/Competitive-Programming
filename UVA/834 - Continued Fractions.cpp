#include<stdio.h>
#include <iostream>
using namespace std; 

int main()

{

	int a , b  ,x , z ; 

     while(scanf("%d%d",&a,&b)==2)
    {

		z=0 ; 
     while (b)
	  {
		  if (z==0)
			  cout <<"["<<a/b<<";";
		  else if(z==1)
			  cout <<a/b;
		  else 
			  cout <<","<<a/b;
		  
		  x=b ; 
		  b=a%b ; 
		  a=x;
		  z++;
		
      }

	 cout << "]"<<endl; 

	 }
return 0 ;
}

