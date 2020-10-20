#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
char ans[500] = "";
void rec(int k,int a,int b,int idx){
	if(a == k || b == k){
		for(int i=0;i<idx;i++){
			printf("%c",ans[i]);
			if(i != idx-1){
				printf(" ");
			}
		}
		printf("\n");
	} else{
		ans[idx] = 'W';
		rec(k,a+1,b,idx+1);
		ans[idx] = 'L';
		rec(k,a,b+1,idx+1);
	}
	
}
int main(){
	int k,a,b;
	scanf("%d %d %d",&k,&a,&b);
	rec(k,a,b,0);
	return 0;
}