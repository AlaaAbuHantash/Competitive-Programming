#include <iostream>
using namespace std; 

 
int main()
{

	  int n  , r  ; 
	   cin >> n ; 
	  while (n != 0 )
	  {
	  r = (n*n) - n +1 ; 
	  cout << n << " => " << r << endl;
	  cin >> n ; 
	  }
return 0;
}

