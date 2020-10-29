#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 1005;
int a[maxN],b[maxN],n,m;
pair<int,int> dp[maxN][maxN]; //day and time
void print(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			printf("(%d,%d) ",dp[i][j].first,dp[i][j].second);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	//cal first job of a
	dp[1][0].first = 0;
	dp[1][0].second = a[1];
	if(dp[1][0].second == m){
		dp[1][0].first = 1;
		dp[1][0].second = 0;
	}

	//cal first job of b
	dp[0][1].first = 0;
	dp[0][1].second = b[1];
	if(dp[0][1].second == m){
		dp[0][1].first = 1;
		dp[0][1].second = 0;
	}

	//cal first column (do only job a)
	for(int i=2;i<=n;i++){
		if(dp[i-1][0].second + a[i] < m){
			dp[i][0].first = dp[i-1][0].first;
			dp[i][0].second = dp[i-1][0].second+a[i];
		} else{
			dp[i][0].first = dp[i-1][0].first+1;
			dp[i][0].second = a[i];
			if(dp[i-1][0].second + a[i] == m){
				dp[i][0].second = 0;
			}
		}
	}

	//cal first row (do only job b)
	for(int i=2;i<=n;i++){
		if(dp[0][i-1].second + b[i] < m){
			dp[0][i].first = dp[0][i-1].first;
			dp[0][i].second = dp[0][i-1].second + b[i];
		} else{
			dp[0][i].first = dp[0][i-1].first+1;
			dp[0][i].second = b[i];
			if(dp[0][i-1].second + b[i] == m){
				dp[0][i].second = 0;
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//dp[i][j] = min(dp[i-1][j]+k1,dp[i][j-1]+k2)
			//cal up (do i-th job in work a)
			int d1 = dp[i-1][j].first;
			int t1 = dp[i-1][j].second;
			if(t1 + a[i] < m){
				t1+=a[i];
			} else{
				d1++;
				if(t1+a[i] == m){
					t1 = 0;
				} else{
					t1 = a[i];
				}
			}

			//cal left (do j-th job in work b)
			int d2 = dp[i][j-1].first;
			int t2 = dp[i][j-1].second;
			if(t2 + b[j] < m){
				t2+=b[j];
			} else{
				d2++;
				if(t2+b[j] == m){
					t2 = 0;
				} else{
					t2 = b[j];
				}
			}

			if(d1 < d2){
				dp[i][j].first = d1;
				dp[i][j].second = t1;
			} else if(d2 < d1){
				dp[i][j].first = d2;
				dp[i][j].second = t2;
			} else{
				if(t1 < t2){
					dp[i][j].first = d1;
					dp[i][j].second = t1;
				} else{
					dp[i][j].first = d2;
					dp[i][j].second = t2;
				}
			}
		}
	}
	if(dp[n][n].second == 0){
		printf("%d\n%d\n",dp[n][n].first,m);
	} else{
		printf("%d\n%d\n",dp[n][n].first+1,dp[n][n].second);
	}
	return 0;
}