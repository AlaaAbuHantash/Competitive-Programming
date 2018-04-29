#include <iostream> 
#include <string>  
#include <vector> 
#include<algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main()
{
	int a , b , c , a2, b2 ,c2 ,t = 0 ; 

	cin >> a >> b >> c >> a2 >> b2 >> c2 ; 

if(a==a2)
t=1 ; 
if (b==b2)
t=1 ; 
if (c==c2 )
t=1;

if(t)
cout <<"YES"<<endl;
else 
cout <<"NO"<<endl;



return 0;
}