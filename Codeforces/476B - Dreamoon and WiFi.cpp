#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
string a, b;
int c;
int calc ( int pos , int sum){
	if ( pos == b.length() && sum == c )
		return 1 ;
	if(pos >= b.length())
		return 0 ;
	int r = 0 ;
	if ( b[pos] == '+')
		r+=calc(pos+1 , sum+1 );
	else if ( b[pos] == '-')
		r+=calc(pos+1 , sum-1 );
	else if ( b[pos] =='?'){
		r+=calc(pos+1 , sum-1 );
		r+=calc(pos+1 , sum+1 );
	}
	return r ;
}
int main() {
	//freopen("input", "rt", stdin);
	cin >> a >> b;
	c = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '-')
			c--;
		else
			c++;
	int zz = 0 ,res=0;
	for (int i = 0; i < b.length(); i++)
		if ( b[i] == '?') zz++;
		else if (b[i] =='-') res--;
		else res++;

	int z = calc(0,0);
	double f ;
	if(res == c && zz ==0 )
		f=1;
	else if( z == 0 )
		f=0;
	else
		f=(double)z/pow(2.0,zz);
	printf("%.12f\n",f);
	return 0;
}

