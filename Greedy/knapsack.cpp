#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class item{
public:
	int w,v;
	double k;
	item(int w,int v,double k){
		this->w = w;
		this->v = v;
		this->k = k;
	}
};
bool cmp(item& left,item& right){
	return left.k > right.k;
}
int main(){	 
	int n,w,v,maxWeight;
	scanf("%d %d",&n,&maxWeight);
	vector<item> vec;
	for(int i=0;i<n;i++){
		scanf("%d %d",&w,&v);
		vec.push_back(item(w,v,1.00*v/w));
	}
	sort(vec.begin(),vec.end(),cmp);
	int cnt = 0;
	double sumWeight = 0, sum = 0;
	for(int i=0;i<n;i++){
		double temp = 0;
		if(sumWeight+vec[i].w <= maxWeight){
			temp = 1;
		} else{
			temp = (maxWeight-sumWeight)/vec[i].w;
		}
		sumWeight+=temp*vec[i].w;
		sum+=temp*vec[i].v;
	}
	printf("%f %f\n",sumWeight,sum);
}
/*
6 12
4 7
3 5
2 6
1 3
5 7
4 8
*/