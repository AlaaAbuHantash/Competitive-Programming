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
	int t  , y , n  , x;
	cin >> t ;
	vector<int > a ;
	set<int > s ; 
	set<int > ::iterator it ; 
	 while ( t-- ) 
	 {
		 cin >> y >> n ; 
		 a.resize(n);
		 for(int i = 0 ; i < n ; i++ ) 
			 cin >> a[i] ;

		 for ( int i = 0 ; i < n ; i ++ ) 
		 {
			 s.insert(a[i] + y) ;
		   for ( int j = i+1 ; j < n ; j ++ ) 
			 {
				s.insert( a[i] + a[j] + y );
				   for ( int k = j+1 ; k < n ; k ++ ) 
				     {  
						 s.insert( a[i] + a[j] + a[k] + y );
					     for ( int g = k+1 ; g < n ; g ++ ) 
						 {
							  s.insert( a[i] + a[j] + a[k] + a[g] + y );
							   for ( int w = g+1 ; w < n ; w ++ ) 
							   {
							       s.insert( a[i] + a[j] + a[k] + a[g] + a[w]+ y );
								     for ( int p= w+1 ; p < n ; p++ ) 
									 {
							              s.insert( a[i] + a[j] + a[k] + a[g] + a[w]+a[p] + y );
										   for ( int l = p+1 ; l < n ; l ++ ) 
										   {
											   s.insert( a[i] + a[j] + a[k] + a[g] + a[w]+a[p] +a[l] + y );
											     for ( int f = l+1 ; f < n ; f ++ ) 
												 {
													 s.insert( a[i] + a[j] + a[k] + a[g] + a[w]+a[p] +a[l] + a[f] + y );
													   for ( int v = f+1 ; v < n ; v ++ ) 
													   {
													
														   s.insert( a[i] + a[j] + a[k] + a[g] + a[w]+a[p] +a[l] + a[f]+a[v] + y );
														     for ( int q = v+1 ; q < n ; q++ ) 
															 {
																 s.insert( a[i] + a[j] + a[k] + a[g] + a[w]+a[p] +a[l] + a[f]+a[v] + a[q] + y );
															 }
													   }
												 }
										   }
									 }
							   }
						 }

				   }
		     }
		 }


		 for (it = s.begin() ; it != s.end() ; it++ )
			 cout <<*it<< endl;

		 s.clear();
	 }
	return 0;
}
