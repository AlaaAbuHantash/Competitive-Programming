#include<stdio.h>
#include <iostream>
#include <vector> 
#include <iomanip>
#include <string>
#include <cmath>

using namespace std; 

int main()

{

 unsigned long long int  N  ; 

	 while (cin>>N)
      {

	if (( N &(N-1))==0) 
		 cout << "TAK"<<endl; 
	 else 
		 cout << "NIE" <<endl; 
	 }



return 0 ;
}

