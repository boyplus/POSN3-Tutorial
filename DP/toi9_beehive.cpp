#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 1005;
int arr[maxN][maxN];
using pii = pair<int,int>;
pii dp[maxN][maxN];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		dp[1][i].first = arr[1][i];
		dp[1][i].second = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2 == 1){
				int mx = max(dp[i-1][j-1].first,dp[i-1][j].first);
				dp[i][j].first = mx+arr[i][j];
				if(dp[i-1][j-1].first == mx)
					dp[i][j].second = dp[i-1][j-1].second;
				if(dp[i-1][j].first == mx)
					dp[i][j].second += dp[i-1][j].second;
			} else{
				int mx = max(dp[i-1][j].first,dp[i-1][j+1].first);
				dp[i][j].first = mx+arr[i][j];
				if(dp[i-1][j].first == mx)
					dp[i][j].second = dp[i-1][j].second;
				if(dp[i-1][j+1].first == mx)
					dp[i][j].second += dp[i-1][j+1].second;
			}
		}
	}
	int mx = dp[n][1].first, cnt = 0;
	for(int i=1;i<=m;i++){
		if(dp[n][i].first == mx){
			cnt+=dp[n][i].second;
		}
		else if(dp[n][i].first > mx){
			mx = dp[n][i].first;
			cnt = dp[n][i].second;
		}
	}
	printf("%d %d\n",mx,cnt);
	return 0;
}