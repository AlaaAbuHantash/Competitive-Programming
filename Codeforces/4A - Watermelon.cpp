#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int w , r  , a; 
	cin >> w ; 
     r = w%2 ;
	 a = r%2 ;

	if (r == 0 &&  a == 0 && w != 2 )
	{
		cout <<"YES" <<endl;
	}
	else 
		cout <<"NO" <<endl; 

  return 0;
}
