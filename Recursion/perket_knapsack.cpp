#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = (int)1e9;
int s[11],b[11],ans = INF;
void solve(int idx,int S,int B,bool selected){
	if(selected) ans = min(ans,abs(S-B));
	if(idx < 0) return;
	solve(idx-1,S*s[idx],B+b[idx],true);
	solve(idx-1,S,B,selected);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&s[i],&b[i]);
	}
	solve(n-1,1,0,false);
	printf("%d\n",ans);
	return 0;
}