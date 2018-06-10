#include<iostream>
#include<stdio.h> 
#include<algorithm> 
#include<vector> 
using namespace std;

int main()
{
	int x ,y ,a , b ; 
	vector<pair<int , int > > v ; 
	scanf("%d%d%d%d",&x,&y,&a,&b) ; 
	for ( int i = a ; i < x+1 ; i++)
		for ( int j = b; j < y+1 ;j++)
			if ( i > j ) 
				v.push_back(make_pair( i , j ) ) ; 

	sort(v.begin() , v.end());
	printf("%d\n",v.size());
	for (int i = 0 ; i < v.size() ; i++) 
		printf("%d %d\n" , v[i].first , v[i].second) ; 
	return 0; 
}