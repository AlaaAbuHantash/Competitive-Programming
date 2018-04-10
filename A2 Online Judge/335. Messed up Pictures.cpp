#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ; 
int gcd( int a , int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int arr[205][205];
int main () {
	//freopen ( "test.in","rt"  , stdin ) ; 
	int t , m , n ,a,b,c=1,xx ,yy ; 
	vector<pair<int , int > > v ;
	vector<pair<pair < int , int >  , pair < int , int > > > s;
	/*
	for (int i = 1 ; i <=100;i++)
	for ( int j = 1 ; j <= 100 ;j++) 
	arr[i][j] = gcd(i,j);
	*/
	scanf("%d",&t); 
	while(t-- ){
		scanf("%d",&m) ;
		v.clear();
		while(m--) {
			scanf("%d%d",&a,&b);
			v.push_back(make_pair(a, b ) ) ;
		}
		scanf("%d",&n); 
		printf("Case %d:\n",c++);
		for ( int i = 0 ; i < n ; i++) {
			scanf("%d%d",&a,&b);
			bool f =  0 ; 

			for ( int j =  0 ; j < v.size(); j++) {

				int ta = a  ,tb = b  , tc = b , td = a ; 
				int aa = a%v[j].first ;  
				int bb= b%v[j].second;  
				if ( aa != 0 ) 
					ta+= (v[j].first-aa) ; 
				if ( bb != 0 ) 
					tb+=(v[j].second-bb);

				xx = max ( ta / v[j].first , tb / v[j].second) ; 

				int cc= b%v[j].first;  
				int dd= a%v[j].second;  
				if ( cc!= 0 ) 
					tc+= (v[j].first-cc) ; 
				if ( dd != 0 ) 
					td+=(v[j].second-dd);

				yy = max ( tc / v[j].first , td/ v[j].second ) ;

				if ( xx == ta/v[j].first && xx == tb/v[j].second   && aa == 0  && bb == 0 ) 
					s.push_back(make_pair ( make_pair (ta*tb , ta ) , make_pair (0 , tb ) )  ); 
				if ( yy == tc/v[j].first && yy== td/v[j].second   && cc == 0  && dd == 0 ) 
					s.push_back(make_pair ( make_pair (tc*td , tc ) , make_pair (1, td ) )  ); 


				ta = v[j].first * xx ; 
				tb = v[j].second * xx ;
				tc = v[j].first * yy ; 
				td = v[j].second * yy ;

				s.push_back(make_pair ( make_pair (ta*tb , ta ) , make_pair (1 , tb ) )  ); 

				s.push_back(make_pair ( make_pair (tc*td , tc ) , make_pair (2 , td ) )  ); 


			}

			sort(s.begin() , s.end() ) ;
			printf("%d %d %d\n",s[0].first.second, s[0].second.second  , s[0].second.first ) ; 
			s.clear();
		}

	}

	return 0 ; 
}