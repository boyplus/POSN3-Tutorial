#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxR = 100,maxVal = 6;
int main(){
	srand(time(NULL));
	int R = rand()%maxR+1;
	int C = rand()%maxR+1;
	int D = rand()%maxR+1;
	printf("%d %d %d\n",R,C,D);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			for(int k=0;k<D;k++){
				int have = rand()%3;
				if(have == 0){
					int val = rand()%maxVal+1;
					printf("%d ",val);
				} else{
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}