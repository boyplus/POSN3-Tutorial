#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 100005;
int arr[maxN],tree[maxN],n;
int getSum(int k){
	int s = 0;
	while(k >= 1){
		s+=tree[k];
		k -= k&-k;
	}
	return s;
}
void add(int k,int x){
	while(k<=n){
		tree[k]+=x;
		k += k&-k;
	}
}
int main(){
	scanf("%d",&n);
	//index base 1
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		add(i,arr[i]);
	}
	int q,a,b;
	char cmd;
	scanf("%d",&q);
	while(q--){
		scanf(" %c",&cmd);
		if(cmd == 'q'){
			scanf("%d %d",&a,&b);
			int s1 = getSum(b);
			int s2 = getSum(a-1);
			int sum = s1-s2;
			printf("sum in range [%d,%d] is %d\n",a,b,sum);
		} else if(cmd == 'a'){
			int index,addNum;
			scanf("%d %d",&index,&addNum);
			add(index,addNum);
		}
	}
	return 0;
}
/*
12
2 1 1 3 2 3 4 5 6 7 8 9
4
q 2 4
q 5 8
a 6 10
q 5 8
*/