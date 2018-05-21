#include <bits/stdc++.h>
using namespace std;
int lastrmv[300005];
int lastseen[300005];
int freq[300005];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	memset(lastrmv,-1,sizeof(lastrmv));
	memset(lastseen,-1,sizeof(lastseen));
	int n, x; 
	scanf("%d%d",&n,&x);
	int ans = 0, i=0;
	queue<pair<int,int> > q ; 
	while(x--){
	    int a,b;
	    scanf("%d%d",&a,&b);
	    if(a==1){
	        freq[b]++;
	        ans++;
	        lastseen[b] = i;
	        q.push(make_pair(i,b));
	        i++;
	    }
	    else if(a == 2){
	        ans=ans-freq[b];
	        freq[b] = 0 ; 
	        lastrmv[b] = lastseen[b];
	    }
	    else {
	        while(q.size()&&q.front().first<b){
	            int pos = q.front().first;
	            int tmp = q.front().second;
	            if(pos > lastrmv[tmp]){
	                lastrmv[tmp]=pos; 
	                ans--;
	                freq[tmp]--;
	            }
	            q.pop();
	        }
	    }
	    printf("%d\n",ans);
	}
	return 0;
}

