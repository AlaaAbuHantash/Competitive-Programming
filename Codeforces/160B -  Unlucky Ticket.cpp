
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std; 

 
int main()


{
	int T  , i , sum1 =0 ; 
	char S[202];

	while ( cin>>T)
	{
		sum1 =0 ;
		for ( i = 0 ; i<T*2 ; i++)
	      cin >> S[i];

sort (S , S+T);
sort (S+T , S+(T*2));
 
 if ( S[0]> S[0+T]) 
   for (i = 0 ; i < T ; i++ )
      {  
	  if ( S[i]> S[i+T])  
		  sum1++ ; }
 else
	   for (i = 0 ; i < T ; i++ )
      { 
    if  ( S[i]< S[i+T])  
          sum1++ ;
	  }


   if ( sum1 == T ) 
	   cout << "YES" <<endl; 
   else 
        cout << "NO" <<endl; 

   
	}
return 0;
}
