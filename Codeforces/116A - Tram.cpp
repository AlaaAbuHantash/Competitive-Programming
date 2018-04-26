
#include <cstdio>
#include <iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std; 

 
int main()
{
int n , i , sum = 0 , x=0  ; 

cin >> n ; 
vector <int>a(n);
vector <int>b(n);

for (i=0 ; i<n ; i++) 
{
	cin >> a[i]>>b[i];
	sum = sum + b[i]-a[i] ; 

	if (sum > x)
		x = sum ; 

}
cout << x << endl;
return 0;
}
