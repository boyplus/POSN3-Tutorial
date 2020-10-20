#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = (int)1e9;
int dp[257];
int main(){
	int n,k,cost;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=256;i++){
		dp[i] = INF;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&cost);
		int sum = 0;
		for(int j=k-1;j>=0;j--){
			int temp;
			scanf("%d",&temp);
			temp = temp<<j;
			sum+=temp;
		}
		dp[sum] = min(dp[sum],cost);
	}
	for(int i=1;i<=256;i++){
		for(int j=i-1;j>0;j--){
			if(dp[i] == INF || dp[j] == INF) continue;
			dp[i|j] = min(dp[i|j],dp[i]+dp[j]);
		}
	}
	printf("%d\n",dp[(1<<k)-1]);
	return 0;
}