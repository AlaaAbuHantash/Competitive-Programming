#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <map> 
using namespace std;

int main()
{
	int n  , i = 0 , m , x , j ,y = 0;

	string name;
	map <string , int > money ; 
	map <string , int> ::iterator it;

	while (cin >> n)
	{
		money.clear();
		if(y)
			cout << endl;
		y++;

	i = 0 ; 
	
	
	vector <string> Name (n+1); 


	while (i != n)
	{
		cin >> Name[i] ;
		i++;
	}


	for (i = 0 ; i < n ; i++)
	{
		cin >> name ; 
		cin >> m ; 
		cin >> x ; 
		if (x==0)
			continue;
		money[name]= money[name]+ m%x - m ;

	//	cout << money[name] << endl; 
		for (j = 0 ; j<x ; j++) 
		{
			cin >> name ;
			money[name]= money[name] + m/x ;
			//cout << "ss"<<endl;
		}
	
	}

	for (i = 0 ; i < n ; i++)
		cout << Name[i] << " "<< money[ Name[i] ]<<endl;



	}



}


