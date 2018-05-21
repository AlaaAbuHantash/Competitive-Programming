#include <bits/stdc++.h>
using namespace std;
int v[100005];
int n , s ; 
int calc(int k ){
    vector<long long>a;
    for(int i = 1 ; i <=n;i++){
        a.push_back((long long)v[i-1] + ((long long)i*(long long)k));
    }
    sort(a.begin(),a.end());
    long long sum =0;
    for(int i = 0 ; i< k;i++){
        sum+=a[i];
    }
    if(sum>(long long)s)
        return -1;
    return sum;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    int l=0,r=n;
    int val=0,ansmid=0;
    while(l<=r){
        int mid =(l+r)/2;
        int ans = calc(mid); 
        if(ans != -1){
            if(mid > ansmid){
                ansmid = mid ; 
                val = ans ;
            }else if ( mid == ansmid)
                val = min(val,ans);
            l = mid + 1 ; 
        }
        else 
            r = mid -1 ; 
    }
    printf("%d %d\n",ansmid,val);
    
	return 0;
}

