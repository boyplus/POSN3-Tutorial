#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 100005,INF = (int)1e9;
int arr[maxN],tree[maxN*2+2],n;
void insert(int k,int x){
	k+=n;
	tree[k] = x;
	for(k=k/2;k>=1;k/=2){
		tree[k] = min(tree[2*k],tree[2*k+1]);
	}
}
int getMin(int a,int b){
	a+=n;
	b+=n;
	int ans = INF;
	while(a<=b){
		if(a%2 == 1) ans = min(ans,tree[a++]);
		if(b%2 == 0) ans = min(ans,tree[b--]);
		a/=2;
		b/=2;
	}
	return ans;
}
int main(){
	int q;
	scanf("%d",&n);
	//index base 0
	for(int i=1;i<=2*n;i++){
		arr[i] = INF;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		insert(i,arr[i]);
	}
	int a,b;
	char cmd;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&a,&b);
		int ans = getMin(a,b);
		printf("Min from [%d,%d] is %d\n",a,b,ans);
	}
}
/*
8
5 8 6 3 1 7 2 6
3
1 6
1 3
0 5 7
*/