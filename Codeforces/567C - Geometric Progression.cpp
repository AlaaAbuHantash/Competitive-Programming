#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int n,k,x;
	scanf("%d%d",&n,&k);
	vector<pair<pair<int,int>, int> > v; 
	for ( int i = 0 ; i < n ; i++){
	    scanf("%d",&x);
	    int c = 0 ; 
	    while(k!=1 && x!=1 && x!=0 && x%k==0){
	        x=x/k;
	        c++;
	    }
	    v.push_back(make_pair(make_pair(x,c),i));
	    
	}
	sort(v.begin(),v.end());
	long long res = 0 ; 
	for ( int i =0 ; i < n ; i++){
	    int b = v[i].first.first;
	    int kn = v[i].first.second;
	    int ind = v[i].second; 
	 
	    if(k!=1 && b!=0){
    	    int a1 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,kn-1),0))-v.begin();
    	    int a2 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,kn-1),ind))-v.begin();
    	    a2--;
    	    if(a2<a1)continue;
    	    int b1 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,kn+1),ind))-v.begin();
    	    int b2 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,kn+1),n))-v.begin();
    	    b2--;
    	    if(b2<b1)continue;
    	    res+=(long long )(a2-a1+1)*(long long )(b2-b1+1);
	    }
	    else {
	        int a1 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,0),0))-v.begin();
    	    int a2 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,0),ind))-v.begin();
    	    a2--; 
    	    if(a2<a1 || ind-1<0 )continue;

    	    int b1 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,0),ind))-v.begin();
    	    int b2 = lower_bound(v.begin(),v.end(), make_pair(make_pair(b,0),n))-v.begin();
    	    b1++;
    	    b2--;
    	    if(b2<b1 || ind+1 ==n )continue;
    	   
    	    res+=(long long)(a2-a1+1)*(long long )(b2-b1+1);
    	   
	    }

	}
	printf("%lld\n",res);
	return 0;
}

