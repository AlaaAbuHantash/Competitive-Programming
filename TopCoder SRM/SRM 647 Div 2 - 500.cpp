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
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>

/*YOU got a DREAM, YOU gotta protect it. */ 

using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

map < int , int >  v; 
class TravellingSalesmanEasy {
public : 
	int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {

		vector<vector < int > > v(M+2)	 ; 
		vector<int > cot(M+2);
		for ( int i = 0 ; i <city.size() ; i++) 
			v[city[i]].push_back( profit[i] ) ;
		for ( int i = 0 ; i <=M ; i++) 
			sort( v[i].rbegin() , v[i].rend());


		for ( int i = 0 ; i <visit.size() ; i++) 
			cot[visit[i]]++;

		int sum = 0 ; 
		for ( int i = 1 ; i <=M ; i++) {
			for ( int j = 0 ; j < cot[i] &&  j < v[i].size(); j++) {
				sum+=v[i][j] ; 
			}

		}
		return sum ; 
	}
};
int  main()
{
	//freopen("input.in" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int a = 2 ; 
	vector<int > b ; 
	vector<int > c ; 
	vector<int > d ; 
	b.push_back(3);
	b.push_back(10);
	c.push_back(1);
	c.push_back(1);
	d.push_back(2);
	d.push_back(1);
	TravellingSalesmanEasy aa ; 
	cout << aa.getMaxProfit(a , b , c , d ) << endl;

	return 0 ;
}