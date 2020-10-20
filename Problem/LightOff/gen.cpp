#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 15,maxm = 100;
int main(){
	srand(time(NULL));
	int n = rand()%maxn+1;
	int m = rand()%maxm+1;
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++){
		printf("0");
		for(int j=0;j<m;j++){
			int tt = rand()%4;
			if(tt == 0){
				printf("1");
			} else{
				printf("0");
			}
		}
		printf("0");
		printf("\n");
	}
    return 0;
}