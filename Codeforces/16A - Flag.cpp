#include <cstdio>
#include <iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std; 

 
int main()
{
	int n , m , i ,j;
	bool f1 ,f2 ; 
	cin >> n >> m ;
	vector <string>s (n);

	for (i=0 ; i < n ; i++)
		cin >> s[i];

	f1 = f2 = 0 ;

for (i=0 ; i < n ; i++)
{
	for (j=1 ; j < m ; j++)
		if (s[i][j-1] != s[i][j])
			f1 = 1 ; 

}


for (i=1 ; i < n ; i++)
if (s[i-1][0] == s[i][0])
f2 = 1 ; 

       if (f1 || f2 )
		   cout << "NO"<<endl;
	   else 
		   cout << "YES" <<endl;


return 0;
}



