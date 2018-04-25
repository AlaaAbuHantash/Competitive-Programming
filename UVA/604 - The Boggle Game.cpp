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
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
string a , b  ,s , temp , t2;
int c ;
vector<string > s1 ; 
vector<string> s2;
vector<bool> e1 ;
vector<bool > e2;
set<string > r1 ; 
set<string > r2 ;
set<string > ::iterator it ;
set<string > ::iterator it2;
vector<string> fr;
vector<vector<bool> > vis;
void dfs1 ( int x , int y  , string re , int vo , int cha) 
{
	if ( vo > 2  || cha > 4 || !e2[s1[x][y]-'A']  || vis[x][y] ) 
		return ; 

	if ( cha == 4  && vo == 2 ) 
	{
		r1.insert(re);
		return;
	}
	vis[x][y] =1 ; 

	for ( int i = 0 ; i < 8 ; i++) {
		int nx = x + dx[i] ; 
		int ny = y + dy[i];
		if (nx >=0 && ny>=0 && ny< 4 && nx <4 ) 
		{
			t2="";
			t2+=s1[nx][ny] ;
			if ( s1[nx][ny] == 'A' || s1[nx][ny]=='E' || s1[nx][ny] =='I'||s1[nx][ny] =='O' || s1[nx][ny]== 'U'||s1[nx][ny]== 'Y')
			   dfs1 ( nx , ny , re +t2 ,vo + 1 , cha + 1 ) ; 
			else 
			   dfs1 ( nx , ny , re +t2 ,vo  , cha + 1 ) ; 
		}
	}

	vis[x][y] =0 ; 
}
void dfs2 ( int x , int y  , string re , int vo , int cha) 
{	
	if ( vo > 2  || cha > 4 || !e1[s2[x][y]- 'A'] || vis[x][y]  ) 
		return ; 

	if ( cha == 4  && vo == 2 ) 
	{
		r2.insert(re);
		return;
	}
	vis[x][y] =1 ; 
	for ( int i = 0 ; i < 8 ; i++) {
		int nx = x + dx[i] ; 
		int ny = y + dy[i];
		if ( nx >=0 && ny>=0 && ny< 4 && nx <4  ) 
		{
			t2 = "" ;
			t2+=s2[nx][ny] ;
			if ( s2[nx][ny] == 'A' || s2[nx][ny]=='E' || s2[nx][ny] =='I'||s2[nx][ny] =='O' || s2[nx][ny]== 'U'||s2[nx][ny]== 'Y')
			   dfs2( nx , ny , re + t2 ,vo + 1 , cha + 1 ) ; 
			else 
			   dfs2 ( nx , ny , re + t2 ,vo  , cha + 1 ) ; 


		}
	}
	vis[x][y] =0 ; 
}
int  main()
{
	bool f, ou = false , en = false;
	freopen("test.in" , "rt" , stdin);
	while (true ) 
	{

		s2.clear() ;
		s1.clear();
		e1.clear() ; 
		e2.clear() ; 
		e1.resize(50) ; 
		e2.resize(50) ; 
		r1.clear();
		r2.clear();
		fr.clear();
	while (getline(cin , s ))
	{
		if (s.empty() ) break;
		c=0;
		f= false;
		a= "" ; b = "";
		rep ( i , sz(s)) {
			if (s[i] == ' ' ) {
				c++;
			   continue;
			}
		
		if ( c > 1 ) 
			f = true;
		c=0;
		if ( f )
			a = a + s[i] ; 
		else 
			b = b + s[i] ;
		
		if ( b == "#" )
			break;

		}
		if ( b =="#")
			ou = true;
		s1.push_back(b) ; 
		s2.push_back(a);

	}

	if ( ou )
		break;
	if ( en ) 
	 cout <<endl;
		en =true;

	rep( i , sz(s1) ) 
		rep ( j , sz(s1[i])) {
			e1[s1[i][j] -'A'] = 1 ;
			e2[s2[i][j] - 'A' ] = 1 ;
     	}

	rep ( i , 4 ) 
		rep(j ,4 )   {
			vis.clear();
			vis.resize(4,vector<bool > ( 4 ) ) ;
			temp="";
			temp+=s1[i][j] ;
			if ( s1[i][j] == 'A' || s1[i][j] =='E' || s1[i][j] =='I'||s1[i][j] =='O' || s1[i][j]== 'U'||s1[i][j]== 'Y')
		       dfs1(i,j , temp , 1 , 1 );
			else
		       dfs1(i,j , temp , 0 , 1 );

			temp="";
			temp+=s2[i][j] ;
			vis.clear();
			vis.resize(4,vector<bool > ( 4 ) ) ;
			if ( s2[i][j] == 'A' || s2[i][j] =='E' || s2[i][j] =='I'||s2[i][j] =='O' || s2[i][j]== 'U'||s2[i][j]== 'Y')
			    dfs2(i,j, temp , 1 , 1 );
			else
		       dfs2(i,j , temp , 0 , 1 );

	      }

	for (it=r1.begin() ; it!=r1.end() ; it++)
		for ( it2=r2.begin() ; it2 != r2.end() ; it2++) {
			//cout << *it<< "   " << *it2 <<endl;
			if ( *it == *it2 ) 
				fr.push_back(*it);
		}

	sort(fr.begin() , fr.end() );
	if ( sz(fr) == 0 ) 
		cout << "There are no common words for this pair of boggle boards."<<endl;
	else
		rep ( i , sz(fr)  ) 
		   cout << fr[i] <<endl;

	}
	return 0 ;
}