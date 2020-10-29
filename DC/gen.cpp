#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main(){
	srand(time(NULL));
	int n = 500;
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		int x = rand()%1000000;
		int y = rand()%1000000;
		printf("%d %d\n",x,y);
	}
	return 0;
}