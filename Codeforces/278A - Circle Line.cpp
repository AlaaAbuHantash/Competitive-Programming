#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n  , i  , sum = 0 , j , x , y , k , s ;
		cin >> n ;
	vector <int > a ( n ) ; 
 
	for ( i= 0 ; i < n ; i ++)
	{
		cin >> a[i] ;
		sum+=a[i];
	}
	cin >> x >> y ; 
	s=0;
	i = min(x,y) - 1;
	j = max(x,y) - 1;
	for( k=i ; k<j ; k++)
		s=s+a[k];

	cout << min ( s , sum-s) << endl;
} 