#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN=270000,NEG = -(int)1e9+7;
int arr[maxN],tree[maxN*2+2],n;
int getMax(int a,int b){
	a+=n;
	b+=n;
	int ans = NEG;
	while(a<=b){
		if(a%2 == 1) ans = max(ans,tree[a++]);
		if(b%2 == 0) ans = max(ans,tree[b--]);
		a/=2;
		b/=2;
	}
	return ans;
}
void insert(int k,int x){
	k+=n;
	tree[k] = x;
	for(k=k/2;k>=1;k/=2){
		tree[k] = max(tree[2*k],tree[2*k+1]);
	}
}
int main(){
	int q;
	scanf("%d %d",&n,&q);
	while(q--){
		char cmd;
		int a,b;
		scanf(" %c %d %d",&cmd,&a,&b);
		if(cmd == 'U'){
			//change value at index a to be b
			a--;
			insert(a,b);
		} else if(cmd == 'P'){
			a--;
			b--;
			int ans = getMax(a,b);
			printf("%d\n",ans);
		}
	}
	return 0;
}