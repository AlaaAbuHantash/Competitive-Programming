#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
int main()
{
	

	//  freopen("test.in" , "rt" , stdin);
	vector<string>s1(4);
	string f[] = { "C", "C#", "D","D#","E","F","F#","G","G#","A","B","H"}  ; 
	vector <string> s (4) ; 

	cin >> s1[0] >> s1[1] >> s1[2] ;
	int x[4] , y1 ,y2 ,y3 ,y4 , y5 ,y6;
	bool f1 = false  , f2 = false ;

		for (int j=0;  j<3 ; j++ ) 
		{
			for ( int k = 0 ; k < 12 ; k++ ) 
			{
				if ( s1[j] == f[k])
					{
						x[j] = k ;
				    }
			}
		}

		sort( x , x+3);
		//cout << x[0] << x[1] << x[2] << endl;
	y1 = x[1] - x[0] ; 
	y2 = x[2] - x[1] ; 

	//cout << y1 << " " << y2 << endl;

	y3 = x[0] - x[2] +12; 
	y4 = x[1] - x[0] ; 

	//cout << y3 << " " << y4 << endl;
	
	y5 = x[2] - x[1] ; 
	y6 = x[0] - x[2] +12; 

	//cout << y5 << " " << y6 << endl;


	if (( y1 == 4 && y2 ==3 ) ||( y3 == 4 && y4 ==3 ) ||( y5 == 4 && y6 ==3 ))
		cout << "major"<< endl; 
	else if (( y1 == 3 && y2 ==4 ) ||( y3 == 3 && y4 ==4 ) ||( y5 == 3 && y6 ==4 ) )
		cout << "minor"<< endl; 
	else 
		cout << "strange"<< endl;
	return 0;
}

