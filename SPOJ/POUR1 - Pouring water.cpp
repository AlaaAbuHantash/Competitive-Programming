#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <stack>
#include<stdio.h>
#include <cstring> 
using namespace std;
bool vis[40001][4];
struct jug 
{
	int a , b , op ;
};
//string arr[6] = {"fill A", "fill B", "empty A", "empty B", "pour A B",  "pour B A"} ; 
 int A,B,C;
 int s , ne  , con ;
 
 void bfs (int a , int b , int c) 
 {
	 jug j  , temp , x; 
	 queue<jug> q;
	 j.a= a ; 
	 j.b = 0;
	 j.op = 0;

	 q.push(j);
	 j.a=0;
	 j.b=b;
	 j.op = 1 ; 

	 q.push(j);

	 bool f = false;
 
	 
	 if (  c <= a || c <= b)
	 while ( !q.empty() )
	 {
		  
		 int siz = q.size() ; 

		 while ( siz -- ) 
		 {
	     temp = q.front() ;
		 q.pop() ; 		
		
		 if ( temp.b == c || temp.a == c   )
		 {
			 f=true;
			 break;
		 }

		 // 6 ops .. 
		 if ( temp.a != 0 ) // empty a 
		 {
			 x.a = 0 ;
			 x.b = temp.b;
			 x.op = 2 ; 
			 if ( !vis[x.b][x.op])
			 {
				 vis[x.b][x.op] = 1 ;
				  q.push(x);
				
			 }
			  
		 }
		 if (temp.b != 0 )  // empty b 
		 {
			 x.a = temp.a;
			 x.b = 0 ;
			 x.op = 3 ; 
			 if (!vis[x.a][x.op])
			 {
				vis[x.a][x.op]= 1;
				q.push(x);
				
			 }
			 
		 }

		 if ( temp.a != a ) // fill a 
		 {
			 x.a = a;
			 x.b = temp.b ;
			 x.op = 0 ; 
			 if (!vis[x.b][x.op])
			 {
				 vis[x.b][x.op]=1;
				q.push(x);
				
			 }
		 }
		 
		 if ( temp.b != b ) // fill b
		 {
			 x.a = temp.a;
			 x.b = b ;
			 x.op = 1 ; 

			 if (!vis[x.a][x.op])
			 {
				vis[x.a][x.op] = 1 ;
				q.push(x);
				
			 }
			
		 }

		 if ( temp.b != b && temp.a != 0 ) // pour a b 
		 {
			 ne = b - temp.b ; 

			 if ( ne > temp.a ) 
					s = temp.a ; 
			 else 
				 s = ne ; 

			 x.b = temp.b + s ; 
			 x.a = temp.a - s  ;
			// x.b = temp.b + temp.a ;

			 if ( x.b >= b    ) 
			 {		
				 if (!vis[x.a][1])  
					 {
						 vis[x.a][1] = 1 ;
						 x.op = 1 ;
						 q.push(x);
				 }
			 }
			 else
			 {
				  if (!vis[x.b][2])  
					{
						
						vis[x.b][2]= 1 ; 
						x.op = 2 ;
						q.push(x);
				  }
			 }



			 
		 }

		 if ( temp.a != a && temp.b != 0) // pour b a 
		 {
			 ne = a - temp.a;
			 if ( ne > temp.b)
				 s = temp.b;
			 else 
				 s = ne ;

			 x.a = temp.a + s ;
			 x.b = temp.b - s ;
			// x.op = 5 ; 

			 if ( x.a >= a  ) 
			 {		
				 if (!vis[x.b][0])  
					 {
						 vis[x.b][0] = 1;
						 x.op = 0 ; 
						 q.push(x);
						 
				     }
			 }
			 else
			 {
				  if (!vis[x.a][3])  
					{
						vis[x.a][3] =1 ;
						x.op = 3 ;
						q.push(x);
						
				  }
			 }
			
		 }

		 }
		 con++;// end of the siz ..
		 if  (f ) 
			 break;
	 }
	 if ( f ) 
		 cout << con << endl;
	 else 
		 cout << -1 << endl;

	 while ( !q.empty() ) 
		 q.pop();
 }
int main()
{
	//freopen("test.in" , "rt" , stdin);

	int t ; 
	cin >> t ; 
	while (t-- ) 
	{
		cin >>A >> B >> C ;
		memset(vis ,0 , sizeof(vis) ) ;
		con = 0 ;
		bfs ( A , B , C );
	}

  return 0;
}

