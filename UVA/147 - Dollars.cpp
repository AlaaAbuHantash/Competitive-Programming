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
#include <cmath>
#include <stdio.h>
#include <string.h>
#include<cstdio>

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int va[] = {10000 ,5000 , 2000 , 1000 , 500 , 200 , 100 , 50 , 20 , 10 , 5};
long long  dp [30005][12];
long long   res[30005];
long long  count (long long  x  , int ind )
{
	if ( x < 0 ) 
		return 0 ; 
	if (x == 0 ) 
		return 1 ; 
	if (dp[x][ind] != -1 ) 
		return dp[x][ind];
	long  long sum = 0 ;
	for (int i = ind ; i <= 10 ; i++) {
		 sum = sum + count ( (x - va[i] )  , i ) ;
	}

	dp[x][ind] = sum ;
	return sum;
}
int main()
{
	//freopen("test.in" , "rt" , stdin);

	int x , n1 ,n2 , n  ;
	memset( dp , -1 , sizeof(dp ) );
	long long a = 0 ;
	for ( int i = 0 ; i <= 30000 ; i++  , a++ )
		res[i] = count ( a , 0 ) ;

	while (scanf("%d.%d",&n1,&n2) ) 
	{
		//x = n1 * 100;
		n = n1 * 100 + n2 ; 
		if (n ==  0)
			break;
		
		printf("%3d.%.2d%17llu\n",n1,n2,res[n]);
		//printf("%6.2lf%17lld\n",n,res[x]);

		//printf("%6.2f%17lld\n", n, );
		//printf("%6.2f% 17lld\n", n, res[x]);
	}
	return 0;
}



-------------------------

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

/*
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-9



using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
double n;
long long dp[30001][12];
int v[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	rep(i,11)
		dp[0][i]=1;

	for(int i=5;i<30001;i+=5){
		rep(j,11){
			if(j)
				dp[i][j]= dp[i][j-1];
			if(i-v[j]>=0)
				dp[i][j]+=dp[i-v[j]][j];
		}
	}

	while(cin >> n ) {

		int v=(n+1e-9)*100.0;
		if(n == 0)
			break;
		printf("%6.2lf%17lld\n",n, dp[v][10]);
	}
	return 0 ;
}



------------------------------------

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

/*
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-9



using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
double n;
long long dp[30001][2];
int v[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	int p=0;
	dp[0][1]=1;
	dp[0][0]=1;
	rep(j,11){
		p = !p;
		for(int i=5;i<30001;i+=5){
			dp[i][p]=0;
			if(j)
				dp[i][p]= dp[i][!p];
			if(i-v[j]>=0)
				dp[i][p]+=dp[i-v[j]][p];
		}
	}

	while(cin >> n ) {

		int v=(n+1e-9)*100.0;
		if(n == 0)
			break;
		printf("%6.2lf%17lld\n",n, dp[v][p]);
	}
	return 0 ;
}



--------------------------------------------


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

/*
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-9



using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
double n;
long long dp[30001];
int v[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	dp[0] = 1;

	for (int j = 0; j <11; ++j)
		for (int a = v[j]; a <=30001; a+= 5)
			dp[a] += dp[a-v[j]];

	
	while(cin >> n ) {

		int v=(n+1e-9)*100.0;
		if(n == 0)
			break;
		printf("%6.2lf%17lld\n",n, dp[v]);
	}
	return 0 ;
}