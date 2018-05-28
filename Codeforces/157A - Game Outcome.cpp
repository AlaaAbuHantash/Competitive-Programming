#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
	int n , i  , j , k , count=0 ; 
	int  sumr=0 , sumc = 0;
	cin >> n ; 
	vector<int>r (n*n);
    vector<int>c (n*n);
	for ( i = 0 ; i < n ; i++)
		for ( j = 0 ; j < n ; j++)
			{
				cin >> k ;
				r[i] = r[i] + k ;
				c[j] = c[j] + k ;
			//	cout << r[i] <<  "  " << c[j] <<endl;
		    }


	for ( i = 0 ; i < n ; i++)
		for ( j = 0 ; j < n ; j++)
			if (c[i] > r[j])
				count++;

		cout << count << endl;



	return 0 ; 
}