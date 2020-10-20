#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
char s[16][105];
bool bi[16];
const int INF = (int)1e9;
int main(){
	int n,m,round = 1,ans = INF;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		round*=2;
	}
	//find last top row
	int lastRow = -1;

	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			if(s[i][j] == '1'){
				lastRow = i;
				break;
			}
		}
		if(lastRow != -1){
			break;
		}
	}
	if(lastRow == -1){
		printf("0\n");
		return 0;
	}
	int now = 0;
	while(now < round){
		int cnt = 0,current = 0;
		
		for(int i=n-1;i>=0;i--){
			bool found = false;
			int use = 0;
			if(i == n-1){
				for(int j=0;j<=m;j++){
					if(s[i][j] == '1'){
						int temp = abs(current-j);
						use+=temp;
						current = j;
						found = true;
					}
				}

			} else{
				if(bi[i+1] == 0){
					current = 0;
					for(int j=0;j<=m;j++){
						if(s[i][j] == '1'){
							int temp = abs(current-j);
							use+=temp;
							current = j;
							found = true;
						}
					}
				} else {
					current = m+1;
					for(int j=m+1;j>=0;j--){
						if(s[i][j] == '1'){
							int temp = abs(current-j);
							use+=temp;
							current = j;
							found = true;
						}
					}
				}
			}
			cnt+=use;
			if(i == 0) continue;
			if(i == lastRow) break;
			if(bi[i] == 0){
				//left
				cnt+=(current);
				cnt++;

			} else{
				//right
				cnt+=(m+1-current);
				cnt++;
			}			
		}
		ans = min(ans,cnt);

		//mutate bi
		int idx = n-1;
		while(bi[idx] == true){
			bi[idx] = false;
			idx--;
		}
		if(idx >= 0){
			bi[idx] = true;
		}
		now++;
	}
	printf("%d\n",ans);
	return 0;
}