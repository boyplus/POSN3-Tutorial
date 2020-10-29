#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;
const int maxN = 1005;
double x[maxN], y[maxN];
double cal(int i,int j){
	double dx = x[i]-x[j];
	double dy = y[i]-y[j];
	double d = sqrt(dx*dx+dy*dy);
	return d;
}
int main(){
	int n;
	double ans = 1e9;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf %lf",&x[i],&y[i]);	
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			double d = cal(i,j);
			ans = min(ans,d);
		}
	}
	printf("%f\n",ans);
	return 0;
}
/*
6
2 3
12 30 
40 50
5 1
12 10 
3 4
*/