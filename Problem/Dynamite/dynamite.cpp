#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxR = 105;
int arr[maxR][maxR][maxR];
class dynamite{
public:
	int r,c,d,val;
	dynamite(int r,int c,int d,int val){
		this->r = r;
		this->c = c;
		this->d = d;
		this->val = val;
	}
};
bool cmp(dynamite& left,dynamite& right){
	return left.val > right.val;
}
vector<dynamite> vec;
int main(){
	int R,C,D;
	scanf("%d %d %d",&R,&C,&D);
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			for(int k=1;k<=D;k++){
				scanf("%d",&arr[i][j][k]);
				if(arr[i][j][k]){
					vec.push_back(dynamite(i,j,k,arr[i][j][k]));
				}
			}
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int cnt = 0;
	for(dynamite dyna:vec){
		int r = dyna.r,c = dyna.c, d = dyna.d, val = dyna.val;
		if(arr[r][c][d] == 0) continue;
		queue<dynamite> q;
		q.push(dynamite(r,c,d,val));
		cnt++;
		while(!q.empty()){
			int r = q.front().r,c = q.front().c,d = q.front().d;
			int val = q.front().val;
			q.pop();
			arr[r][c][d] = 0;
			for(int i=r-val;i<=r+val;i++){
				if(i > R || i < 1) continue;
				if(arr[i][c][d]){
					q.push(dynamite(i,c,d,arr[i][c][d]));
					arr[i][c][d] = 0;
				} 
			}
			for(int i=c-val;i<=c+val;i++){
				if(i > C || i < 1) continue;
				if(arr[r][i][d]){
					q.push(dynamite(r,i,d,arr[r][i][d]));
					arr[r][i][d] = 0;
				}
			}
			for(int i=d-val;i<=d+val;i++){
				if(i > D || i < 1) continue;
				if(arr[r][c][i]){
					q.push(dynamite(r,c,i,arr[r][c][i]));
					arr[r][c][i] = 0;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}