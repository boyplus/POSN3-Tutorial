#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = (int)1e9;
bool choose[11];
int s[11],b[11], ans = INF;
void solve(int now,int n){
	if(now == n){
		int S = 1,B = 0;
		bool chk = false;
		for(int i=0;i<n;i++){
			if(choose[i]){
				S*=s[i];
				B+=b[i];
				chk = true;
			}
		}
		if(chk) ans = min(ans,abs(S-B));
	} else{
		choose[now] = true;
		solve(now+1,n);
		choose[now] = false;
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