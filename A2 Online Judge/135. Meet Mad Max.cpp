#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <stack>
#include <cstring> 
#include <cmath>
using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t  ,  n  ; 
	long long x , y , m  , c , f ;
	cin >> t ;
	vector <long long  > a ;
	 while ( t-- ) 
	 {
		 cin >> m >> n ; 
		 f=0;
		 a.resize(n) ; 
		 for ( int i = 0 ; i < n ; i ++ ) 
			 cin >> a[i] ; 

		 sort(a.begin() , a.end()  );
		 for ( int i = 0 ; i < n ; i ++ ) 
			 for ( int j = i+1 ; j < n ; j ++ )
			 {
				 c = a[j] * a[i] ; 
				 //cout << a[i] << " " << a[j] << " " << c << endl;
				 if ( c % m > f ) 
				 {
					 f= c%m ; 
					 x= a[i] ; 
					 y = a[j] ; 
				 }
			 }

			 cout <<x << " " << y << endl;
			 a.clear();
	 }
	return 0;
}
