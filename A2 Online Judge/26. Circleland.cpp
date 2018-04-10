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
int t ,n ,ind;
long long int  sum , x , sum1 , sum2 , s , y , m;
vector <long long int> a ; 


int main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >>t ; 
	while (t--) {
		cin >> n ; 
		a.resize(n ) ; 

		sum = 0;
		m=0;
		s = 1000000000;
		for (int i = 0 ; i < n ; i ++) {
		  cin >> a[i] ; 
		  sum+=a[i];
		  if ( a[i] > m ){
			  ind=i;
			  m=a[i];
		  }
		}

		sum1 = 0;
		sum2 = sum;

		if ( ind == 0 ) 
			s = min (s , sum - a[0] ) ; 
		else if ( ind == n-1 ) 
			s= min ( s, sum  - a[n-1] ) ; 

		for ( int i = 0 ; i < n ; i ++)
		{
			sum2 = sum2 - a[i] ;
			//cout << sum1 << " " << sum2 << endl;

			x= sum1 * 2 + sum2 ; 
			y = sum2 * 2 + sum1; 
			s = min ( s , min ( x ,y ) ) ;
			//cout << s << endl;	

			sum1 = sum1 + a[i] ; 

		}
					



		cout << s << endl;


		a.clear();
	}
    return 0;
}