#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int i , n ;
	string s , t2, t1 ; 
	cin >> n ; 
	bool f2=false , f1 =false;
	getline (cin , s ) ;
	while(n--)
	{
	
		f2=false ; f1 =false;
		getline (cin , s ) ;
		if (s.length()>=5)
		{
		t1 = s.substr(s.length()-5) ;
		//cout << t1 << endl;
		if(t1 == "lala." ) 
			f1 = true;
		t2 = s.substr(0,5);
		if(t2=="miao.")
			f2=true;
		}
		if(!f1 && f2 ) 
			cout << "Rainbow's" << endl;
		else if (f1 && !f2 )
			cout << "Freda's" << endl;
		else 
			cout << "OMG>.< I don't know!" << endl;
	}
	return 0;
}