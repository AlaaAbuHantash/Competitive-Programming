#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()

{
int T ,K,N , i ,sum;
int n[100];
cin>>T;
while(T--)
{
	cin >> N; 
	cin >> K; 
  
	 sum = 0 ;
	
	for(i= 0 ; i<N ; i++)
		{
			cin >> n[i];
			sum = sum  + (n[i]/K);
	     }

	cout << sum << endl; 


}

return 0 ;
}
