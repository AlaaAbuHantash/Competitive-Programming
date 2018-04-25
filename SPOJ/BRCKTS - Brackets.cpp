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
#include <cmath>
#include<cstdio>
#include<deque>
#include<sstream>

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

/*

هي فكرة الـ segment tree بحسن انه بكون عندك شغلات بتتعدل وكل تعديل باثر على باقي الاشياء ..
فانه يتغيير كل اشي مرة واحدة .. 
مشان تعرفي تجاوبي على الاشي اللي بسأل عنه كمان بسرعة
زي السؤال اللي جبتيه كيف بس تعدلي تروحي تشيكي على الـ string انه زابط او لا وانتي بتعدلي
فلما يسألك زابط او لا انتي بتكون حاسبي الجواب من اخر تعديل

*/
class SegmentTree
{
public :
	int x ,siz ; 
	string b;
	vector<pair <int , int > > a ;

	SegmentTree (int n , string s ) 
	{
		a.clear();
		b=s; 
		x = (int)(ceil(log(n)/log(2.0)))+1;
		siz = (int)pow(2.0,x);  
		a.resize(siz);   // 7 
		//build(0 , n-1);
	}
	//int build(int s , int e , int p=1) {  // in main s =  0 ; e =  n // call build(0, MAX) to initialzie all cells to val = 1
	//	//cout << s << " " << e << "    " << p << endl;
	//	if ( s==e )
	//		return a[p] = 1 ; 
	//	return a[p] = build (s ,(s+e)/2 , 2*p) + build((s+e)/2+1,e,2*p+1);
	//}

	void insert(int s, int e , int p = 1 ) {

		
		if (s==e)
		{
			if ( b[s] == '(' ) {
				a[p].first= 0;
				a[p].second= 1;
			}
			else {
				a[p].first= 1;
				a[p].second= 0;
			}

		}
		else {
			insert(s,(s+e)/2,2*p);
			insert((s+e)/2+1,e,2*p+1 );

		//	a[p].first  = a[p*2].first + a[p*2+1].first - min(a[p*2].first + a[p*2+1].first , a[p*2].second + a[p*2+1].second ); 
		//	a[p].second = a[p*2].second + a[p*2+1].second - min(a[p*2].first + a[p*2+1].first , a[p*2].second + a[p*2+1].second ); 

			
			a[p].first  = a[p*2].first + a[p*2+1].first ;
			a[p].second = a[p*2].second + a[p*2+1].second ;
		
			int x = min ( a[p*2].second  ,a[p*2+1].first) ; 
			a[p].second  = a[p].second  - x ;
			a[p].first   = a[p].first -x ;
		}

	//	cout << s << " " << e << " " << p << " " << a[p].first << " " << a[p].second << endl;
	}


	void replacement (int pos , int s , int e , int p =1) {
		if (s==e)
		{
			if ( b[pos] == '(' ) {
				a[p].first+=1;
				a[p].second-=1;
				b[pos] = ')';
			}
			else {
				a[p].first-=1;
				a[p].second+=1;
				b[pos]='(';
			}

		}

		else {
			if ( pos <= (s+e)/2) 
				replacement(pos ,s,(s+e)/2,2*p);
			else 
				replacement(pos , (s+e)/2+1,e,2*p+1 );

			a[p].first  = a[p*2].first + a[p*2+1].first ;
			a[p].second = a[p*2].second + a[p*2+1].second ;

			int x = min ( a[p*2].second  ,a[p*2+1].first) ; 
			a[p].second  = a[p].second  - x ;
			a[p].first   = a[p].first -x ;
		}
	}

	void display(int s , int e , int p = 1 ) {
		if ( s == e ) 
			return ; 
			display (s, (s+e)/2 , 2*p ) ; 
			display ((s+e)/2+1 , e , 2*p+1 ) ; 
		
	//	cout << p << " " << s << " " << e << " " << a[p].first << " " << a[p].second << endl; 
		
	}


	bool check(int p=1) {
		//cout <<  a[p].first << " " <<  a[p].second  <<endl;
		if ( a[p].first == a[p].second  && a[p].second == 0 && a[p].first == 0 ) 
			return true;
		return false;
	}
};
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t = 10  , c = 1;
	string  s ; 
	int n , x  , m ;
	while (t-- ) {
		printf("Test %d:\n" , c++ ) ; 
		scanf("%d",&n ) ; 
		cin >> s; 
		SegmentTree st(n , s) ;
		st.insert(0,n-1);
		//st.display(0 , n-1);
		scanf("%d",&m) ; 
		rep(i,m){
			scanf("%d",&x ) ; 
			if(x)
			{
				x--;
				st.replacement(x,0,n-1);
				//st.display(0 , n-1);

			}
			else
			{
				if(st.check())
					printf("YES\n");

				else
					printf("NO\n");
			}
		}
	}
	return 0 ;
}
