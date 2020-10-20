#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 100005;
int arr[maxN],tree[maxN*2+2],n;
int getSum(int a,int b){
	a+=n;
	b+=n;
	int sum = 0;
	while(a<=b){
		if(a%2 == 1) sum+=tree[a++];
		if(b%2 == 0) sum+=tree[b--];
		a/=2;
		b/=2;
	}
	return sum;
}
void add(int k,int x){
	k+=n;
	tree[k]+=x;
	for(k = k/2;k>=1;k/=2){
		tree[k] = tree[2*k]+tree[2*k+1];
	}
}
int main(){
	int q;
	scanf("%d",&n);
	//index base 0
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		add(i,arr[i]);
	}
	int a,b;
	char cmd;
	scanf("%d",&q);
	while(q--){
		scanf(" %c",&cmd);
		if(cmd == 'q'){
			scanf("%d %d",&a,&b);
			int sum = getSum(a,b);
			printf("sum in range [%d,%d] is %d\n",a,b,sum);
		} else if(cmd == 'a'){
			int index,addNum;
			scanf("%d %d",&index,&addNum);
			add(index,addNum);
		}
	}
}
/*
12
2 1 1 3 2 3 4 5 6 7 8 9
4
q 1 3
q 4 7
a 5 10
q 4 7
*/