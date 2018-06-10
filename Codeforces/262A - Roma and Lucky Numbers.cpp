#include <iostream> 
#include <string>  
#include <vector> 
using namespace std;

int main()
{

	int n  , max , i ,c=0 , l=0 , j; 
	cin >> n  >> max ; 
	vector<string>a(n);

	for(i=0; i<n;i++)
	{
	l=0;
		cin >> a[i];
		for (j=0 ;j<a[i].length() ; j++)
			if ( a[i][j] == '7' || a[i][j] == '4' ) 
				l++;

	if (l <= max )
		c++;

	}

	cout << c<<endl;



return 0;
}