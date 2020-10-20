#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class activity{
public:
	int s,e;
	activity(int s,int e){
		this->s = s;
		this->e = e;
	}
};
bool cmp(activity& left,activity& right){
	return left.e < right.e;
}
int main(){	 
	int n,s,e;
	scanf("%d",&n);
	vector<activity> vec;
	for(int i=0;i<n;i++){
		scanf("%d %d",&s,&e);
		vec.push_back(activity(s,e));
	}
	sort(vec.begin(),vec.end(),cmp);
	int cnt = 0, now = 0;
	for(int i=0;i<n;i++){
		if(vec[i].s >= now){
			now = vec[i].e;
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
/*
6
4 7
3 5
2 6
1 3
5 7
4 8
*/