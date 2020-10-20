#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		vector<int> vec;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				vec.push_back(j);
			}
		}
		for(int x:vec){
			printf("%d ",x);
		}
		printf("\n");
	}
    return 0;
}