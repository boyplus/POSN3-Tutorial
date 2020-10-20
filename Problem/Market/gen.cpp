#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int maxn = 100000,maxs = 1000000000,maxa = 100000;
int main(){
	srand(time(NULL));
	int n = rand()%maxn+1;
	int s = rand()%maxs;
	printf("%d %d\n",n,s);
	for(int i=0;i<n;i++){
		int a = rand()%maxa+1;
		printf("%d ",a);
	}
    return 0;
}