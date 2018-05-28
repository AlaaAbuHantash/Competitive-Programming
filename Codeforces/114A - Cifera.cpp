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
	int x , y  , c ; 
	cin >> x >> y ; 
	c=0;
	while(y%x == 0)
	{
		y = y / x ;
		c++;
	}


	if(y==1)
	{
		cout <<"YES"<<endl;
		cout << c - 1 << endl;

	}
	else
		cout << "NO"<<endl;
}
