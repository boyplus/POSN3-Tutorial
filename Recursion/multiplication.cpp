#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int mul(int a,int b){
	if(b == 0) return 0;
	return a+mul(a,b-1);
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int ans = mul(a,b);
	printf("%d\n",ans);
	return 0;
}