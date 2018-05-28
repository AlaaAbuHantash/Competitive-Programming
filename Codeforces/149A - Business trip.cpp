#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int di[] = {1 , -1 , 0 , 0 };
int dj[] = {0 , 0 , 1 , -1};
struct node 
{
	int i , j , c ; 
};
int main()
{

	int n  , i , c=0  ,sum =0; 
	cin >> n ; 
	vector<int> a (12 ) ; 
	for ( i = 0 ; i < 12 ; i++) 
		cin >> a[i] ;

	sort(a.begin(), a.end() ) ;

	//cout << a[11] << endl;
	i=11;
	while (sum <= n)
	{
		if ( sum == n ) 
			break;
		sum = sum + a[i] ; 
		c++ ; 
		
		if ( i== 0 ) 
			break;
		i--;
	}
	if ( sum < n ) 
		cout << -1 << endl;
	else 
	cout << c << endl;

	return 0;
}