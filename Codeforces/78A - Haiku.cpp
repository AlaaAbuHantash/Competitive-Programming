#include <iostream> 
#include <string>  
#include <vector> 
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
	int i  , ca=0, cb=0,cc=0; 
	string a , b , c ; 
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	for(i=0;i<a.length();i++)
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' )
			ca++;
	for(i=0;i<b.length();i++)
		if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u' )
			cb++;
	for(i=0;i<c.length();i++)
		if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u' )
			cc++;

	if (cc==5 && ca==5 &&cb==7)cout<<"YES"<<endl;
	else cout <<"NO"<<endl;
return 0;
}