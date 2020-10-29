#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 1005;
int A[maxN],B[maxN],dp[maxN][maxN];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&B[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i] == B[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			} else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n",dp[n][m]);
}

/*
7 6
2 3 4 1 1 3 4
1 3 4 2 1 3
*/