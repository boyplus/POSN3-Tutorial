#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
void rec(int now,int n){
	if(now == n){
		for(int x:vec){
			printf("%d ",x);
		}
		printf("\n");
	} else{
		//choose
		vec.push_back(now);
		//continue search
		rec(now+1,n);
		//not choose
		vec.pop_back();
		//continue search
		rec(now+1,n);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rec(0,n);
    return 0;
}