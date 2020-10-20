#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int fibo(int n){
	if(n < 2) return n;
	return fibo(n-1)+fibo(n-2);
}
int main(){
	int n;
	scanf("%d",&n);
	int ans = fibo(n);
	printf("%d\n",ans);	 
    return 0;
}