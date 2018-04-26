#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include<iomanip>

using namespace std;
int main()
{
double p= 3.1415926536;
int T ,i  ;
double sum = 0.0 ;
vector <int> nub (200);
cin >>T ;
for( i= 0; i<T ; i++)
{    
	cin >> nub[i];

}

sort(nub.rbegin(), nub.rend());


for( i=0 ; i<T ; i++)
{    
	if (i%2 == 0 && i !=1 )
        sum= sum + (nub[i]*nub[i]);
    else 
		sum= sum - (nub[i]*nub[i]); 

}

cout << sum * p <<endl;


return 0;
}
