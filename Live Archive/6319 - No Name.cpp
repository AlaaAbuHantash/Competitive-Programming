#include <iostream>
#include <string>

using namespace std; 

int main ()
{
    int T , x ,y, i; 
	string  s ,r , P  ; 
    cin >>T ; 
	while (T--)
	{
	cin >>s >> P ; 
	x =0 ; 
	y = 0 ; 
	while (P[0] != 'E')
	{
		if (P == "I") 
		{
			cin>> r >> x ; 
          s= s.substr(0,x) + r + s.substr(x);
		}
		else if (P == "P") 
		{
        cin >> x >> y ; 
		cout << s.substr(x,y-x +1)<<endl;
		}

	  	cin >> P; 

	}
	}
return 0;
}

