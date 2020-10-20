#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = (int)1e9;
int s[11],b[11], ans = INF;
vector<int> vec;
void solve(int now,int n){
	if(now == n){
		if(vec.empty()) return;
		int S = 1,B = 0;
		for(int x:vec){
			S*=s[x];
			B+=b[x];
		}
		ans = min(ans,abs(S-B));
	} else{
		vec.push_back(now);
		solve(now+1,n);
		vec.pop_back();
		solve(now+1,n);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&s[i],&b[i]);
	}
	solve(0,n);
	printf("%d\n",ans);
	return 0;
}