#include <iostream>
using namespace std;
int t,n,a,dp[101][101],v[101][101]; 
int f(int i,int j){if (i==n)return 0; if(dp[i][j]!= -1)return dp[i][j];int sum=0;sum=max(sum,max(f(i+1,j)+v[i][j],f(i+1,j+1)+v[i][j]));return dp[i][j]=sum;}
int main(){cin>>t;while(t--){cin>>n;memset(dp,-1,sizeof(dp));memset(v,0,sizeof(v));for(int i=0;i<n;i++)for(int j=0;j<=i;j++)cin>>v[i][j];cout<<f(0,0)<<endl;}return 0;}

---------------------------------
yousef solution 

#include<bits/stdc++.h>
using namespace std;
#define si(a) scanf("%d",&a)
main(){int t,n,x,y,i,j;si(t);while(t--){int
 d[102][102]={};for(si(n),y=0,i=1;i<=n;++i)for(j=1;j<=i&&si(x);
y=max(y,d[i][j]=x+max(d[i-1][j],d[i-1][j-1])),++j);printf("%d\n",y);}}

----------------------------

#include <iostream>
using namespace std;
int t,n,a,r;
int main(){cin>>t;while(t--){cin>>n;r=0;int d[102][102]={};for(int i=0;i<n;i++)for(int j=0;j<=i;j++){cin>>a;r=max(r,d[i+1][j+1]=a+max(d[i][j+1],d[i][j]));}cout<<r<<endl;}}
