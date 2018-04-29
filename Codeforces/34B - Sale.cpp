
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
	int n , m ,i,sum=0 ; 
	cin >> n >> m ; 
	vector<int> a (n) ; 
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin() , a.end());

	for(i=0;i<m;i++)
	{
		if(a[i]<0)
		sum=sum+a[i];
	}
	sum = sum * -1 ;
	cout << sum<<endl;
	return 0;
}

