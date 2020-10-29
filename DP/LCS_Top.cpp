#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 1005;
int A[maxN],B[maxN],dp[maxN][maxN];
int lcs(int n,int m){
	if(n <= 0 || m <= 0) return 0;
	if(dp[n][m]) return dp[n][m];
	int a = lcs(n-1,m);
	int b = lcs(n,m-1);
	int c = 0;
	if(A[n] == B[m]) c = 1;
	c += lcs(n-1,m-1);
	return dp[n][m] = max(a,max(b,c));
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&B[i]);
	}
	int ans = lcs(n,m);
	printf("%d\n",ans);
}

/*
7 6
2 3 4 1 1 3 4
1 3 4 2 1 3
*/