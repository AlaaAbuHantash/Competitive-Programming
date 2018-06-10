#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include <algorithm>
using namespace std;
int main() 
{
	vector <int> s(3);
	vector <int> t(3);
	string e[3] = {"chest" , "biceps" , "back" };
	int n  , i , x; 
	cin >> n ;

	for( i=0;i<n;i++)
	{
		cin >> x;
		s[i%3]+=x;
	}
	t=s;
	sort(s.begin(), s.end());

	for ( i=0 ; i< 3 ; i++ )
	{
		if(s[2] == t[i])
			cout << e[i]<<endl;
	}
	return 0 ; 
}