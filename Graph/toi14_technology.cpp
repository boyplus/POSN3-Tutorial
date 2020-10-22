#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 100005;
vector<int> vec[maxN],level[maxN];
int indeg[maxN],t;
bool visited[maxN],choose[maxN];
int color[maxN];
void dfs(int u){
	if(color[u] == 1){
		t = -1;
		return;
	}
	color[u] = 1;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(color[v] != 2) dfs(v);
	}
	color[u] = 2;
	t--;
}
int main(){
	int n,k,l,num,u;
	scanf("%d %d %d",&n,&k,&t);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l,&num);
		indeg[i] = num;
		level[l].push_back(i);
		for(int j=0;j<num;j++){
			scanf("%d",&u);
			vec[i].push_back(u);
		}
	}
	int ans;
	for(ans=1;ans<=k;ans++){
		for(int j=0;j<level[ans].size();j++){
			int u = level[ans][j];
			if(color[u] == 0) dfs(u);
		}
		if(t <= 0) break;
	}
	if(t < 0) ans--;
	if(ans == 0) printf("-1\n");
	else printf("%d\n",ans);	
	return 0;
}

/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1
*/