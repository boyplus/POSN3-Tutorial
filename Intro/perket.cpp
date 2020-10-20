#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int s[11],b[11];
const int INF = (int)1e9;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&s[i],&b[i]);
	}
	int ans = INF;
	for(int i=1;i<(1<<n);i++){
		vector<int> vec;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				vec.push_back(j);
			}
		}
		int S = 1,B = 0;
		for(int x:vec){
			S*=s[x];
			B+=b[x];
		}
		int temp = abs(S-B);
		ans = min(ans,temp);
	}
	printf("%d\n",ans);
    return 0;
}