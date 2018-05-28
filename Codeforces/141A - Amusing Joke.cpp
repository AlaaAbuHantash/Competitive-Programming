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
	string a , b , c ; 
	cin >> a >> b >> c ; 
	a=a+b ; 
	sort(a.begin(), a.end() ) ;
	sort(c.begin(), c.end() ) ;
	if(a==c)
		cout <<"YES"<<endl;
	else
		cout <<"NO"<<endl;

}
